#pragma once
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/PlataformaGelo.h"
#include "../Entidades/Obstaculos/Espinho.h"
#include "../Entidades/Obstaculos/Gosma.h"
#include "../Entidades/Personagens/Fantasma.h"
#include "../Entidades/Personagens/Lagarto.h"
#include "../Estados/MenuPrincipal.h"
#include <string>
#include <fstream>
#include <nlohmann/json.hpp> 


#include "../../json.hpp" // Inclui a biblioteca JSON
using namespace Listas;
using json = nlohmann::json;


namespace Fases {

class Fase : public Ente {

    protected:

        ListaEntidades* listaJogadores;
        ListaEntidades* listaInimigos;
        ListaEntidades* listaObstaculos;
        ListaEntidades* listaPlataforma;
        bool ehCoop;
        Gerenciadores::Gerenciador_Grafico* p_GG;
        Gerenciadores::Gerenciador_Eventos* p_GE;
        Gerenciadores::Gerenciador_Colisoes* p_GC;

        std::string caminho; 

    public:

        Fase(bool coop = 0); //
        ~Fase();

        void criaJogadores();
        json lerJSON(const std::string caminho); 
        void constroiFase(); //implementar rand() de obstaculos e condicao para 1 ou 2 jogadores
        virtual void criaFundo() = 0; 
        vector<vector<vector<int>>> converteJsonParaMatriz(const std::string& caminhoArquivoJson, int numLayers);
        void criarTudo(int posx, int poxy, int valor);
        void tratarColisoes();
        void tratarEventos(); 
        virtual void setCaminho(std::string caminhoArq) = 0; 
        virtual void atualizar() = 0;
        virtual void executar() = 0; 
        virtual void desenhar() = 0;
};

}
