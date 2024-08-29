#pragma once
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/PlataformaGelo.h"
#include "../Entidades/Obstaculos/Gosma.h"
#include "../Entidades/Personagens/Fantasma.h"
#include "../Entidades/Personagens/Lagarto.h"

#include <fstream>

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
        void criaInimigos();
        void criaObstaculos();
        void criaPlataforma();

        json lerJSON(const std::string caminho); //
        void constroiFase();
        void criaFundo(); //
        vector<vector<vector<int>>> converteJsonParaMatriz(const std::string& caminhoArquivoJson, int numLayers);
        void criarTudo(int posx, int poxy, int valor);

        void tratarColisoes();
        void tratarEventos(); //
        void atualizar(); //
        void executar(); //
        void desenhar(); 
};

}
