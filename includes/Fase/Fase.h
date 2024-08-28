#pragma once
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Listas/ListaEntidades.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Personagens/Fantasma.h"

using namespace Listas;

namespace Fases {

class Fase : public Ente {

    protected:

        Personagens::Jogador jogador1;
		Personagens::Jogador* jogador2;

        ListaEntidades listaFantasmas;
        ListaEntidades listaPlataformas;

        Gerenciador_Grafico* p_GG;
        Gerenciador_Eventos* p_GE;
        Gerenciador_Colisoes* p_GC;

        sf::RenderWindow* janela_fase;

    public:

        Fase(); //
        ~Fase();

        void criaJogadores(bool coop);
        void criaInimigosMedios();
        void criaPlataforma();
    /*
        void lerJSON(); //
        void criaFundo(); //
        void criaMapa();  //
    */
        void tratarColisoes();
        void tratarEventos(); //
        void atualizar(); //
        void executar(bool coop); //
        void desenhar(); 
        virtual void inicializar();
};

}
