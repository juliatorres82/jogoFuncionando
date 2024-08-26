#include "../../includes/Fase/Fase.h"
#include "Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;

Fase:: Fase() {
 ///
}

Fase::~Fase() {

    /* desalocando jogadores*/
    Lista<Entidade>::Iterador it = listaJogadores.getInicio();
    Entidade* pE = NULL;

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }
    listaJogadores.limpar();


   /* desalocando inimigos*/
    it = listaInimigos.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }
    listaInimigos.limpar();


    /* desalocando obstaculos*/
    it = listaObstaculos.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }

    listaObstaculos.limpar();


     /* desalocando plataformas*/
    it = listaPlataforma.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }

    listaPlataforma.limpar();

}


void Fase:: criaJogadores(){

    Jogador* jogador1 = NULL;

    if(p_GE->isDoisJogadores()){
        Jogador* jogador2 = NULL;
        jogador2 = jogador1->getJogador2();
        jogador2 = new Jogador();
        listaJogadores.incluir(jogador2);
    }

    jogador1 = new Jogador();
    listaJogadores.incluir(jogador1);
}


void Fase:: criaInimigos(){ // mudar mais tarde conforme formos criando os inimigos e colocando os rands();

   Fantasma* fantasma1 = NULL;
   fantasma1 = new Fantasma();
   listaInimigos.incluir(fantasma1);

}


void Fase:: criaObstaculos(){ 

    //qndo criarmos obstáculos concretos
}


void Fase:: criaPlataforma() { 

    Obstaculos::Plataforma* plat = NULL;
    plat = new Plataforma();
    listaPlataforma.incluir(plat);

}


void Fase:: tratarColisoes(){
    
    p_GC->tratarColisoes();

}

void Fases::Fase::tratarEventos()
{
    p_GE->apertaTecla();
}
 void Fases::Fase::executar()
{
    criaPlataforma();
    criaPlataforma();
    criaJogadores();
    criaInimigos();

    while(p_GG->janelaAberta())
    {
        atualizar();
    }
}

void Fase::atualizar() {

    tratarEventos();
    tratarColisoes();
    desenhar();
}

void Fase:: desenhar() {

    pGG->desenharEnte(this);
}
