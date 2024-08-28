#include "../../includes/Fase/Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;

Fase:: Fase() {
 ///
}

Fase::~Fase() {

    /* desalocando jogadores*/
    if(jogador2 != nullptr)
        delete jogador2;
    Entidade* pE = nullptr;



   /* desalocando inimigos*/
    Lista<Entidade>::Iterador it = listaFantasmas.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }
    listaFantasmas.limpar();


    /* desalocando obstaculos*/
    it = listaPlataformas.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }

    listaPlataformas.limpar();


     /* desalocando plataformas*/
    it = listaPlataformas.getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != NULL)
        delete pE;

       pE = NULL;
       ++it;
    }

    listaPlataformas.limpar();

}


void Fase::criaJogadores(bool coop){

    jogador1.setPosicao(100.f, 100.f);
    if(coop){
        jogador2 = new Jogador(&jogador1);
        p_GC->incluirJogador(jogador2);
        jogador1.setJogador2(jogador2);
        jogador2->setJogador2(&jogador1);
    }
    else{
        jogador2 = nullptr;
    }
}


void Fase:: criaInimigosMedios(){ // mudar mais tarde conforme formos criando os inimigos e colocando os rands();

   Fantasma* fantasma1 = NULL;
   fantasma1 = new Fantasma();
   listaFantasmas.incluir(fantasma1);

}


void Fase:: criaPlataforma() { 

    Obstaculos::Plataforma* plat = NULL;
    plat = new Plataforma();
    listaPlataformas.incluir(plat);

}


void Fase:: tratarColisoes(){
    
    p_GC->tratarColisoes();

}

void Fases::Fase::tratarEventos()
{
    p_GE->gerencia();
}
 void Fases::Fase::executar(bool coop)
{
    criaPlataforma();
    criaPlataforma();
    criaJogadores(coop);
    criaInimigosMedios();

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
