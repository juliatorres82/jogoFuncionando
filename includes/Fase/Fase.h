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

        ListaEntidades listaJogadores;
        ListaEntidades listaInimigos;
        ListaEntidades listaObstaculos;
        ListaEntidades listaPlataforma;

        Gerenciador_Grafico* p_GG;
        Gerenciador_Eventos* p_GE;
        Gerenciador_Colisoes* p_GC;

    public:

        Fase(); //
        ~Fase();

        void criaJogadores();
        void criaInimigos();
        void criaObstaculos();
        void criaPlataforma();

        void lerJSON(); //
        void criaFundo(); //
        void criaMapa();  //

        void tratarColisoes();
        void tratarEventos(); //
        void iniciar(); //
        void executar(); //
        void desenhar(); 
};

}
