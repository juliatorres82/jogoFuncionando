#include "Fase1.h"

Fases::Fase1::Fase1()
{
    janela_fase = pGG->getJanela();
    jogador1.setGG(pGG);

    p_GC->incluirObstaculos(&plataforma1);
    p_GC->incluirObstaculos(&plataforma2);
    p_GC->incluirObstaculos(&plataforma3);

    p_GC->incluirInimigos(&fantasma1);

    p_GC->incluirJogador(&jogador1);
    
    jogador1.setPosicao(100.f, 100.f);
    fantasma1.setPosicao(200.f, 100.f);
}

Fases::Fase1::~Fase1()
 {

 }


void Fases::Fase1::executar()
{

}

void Fases::Fase1::desenhar()
{

}

void Fases::Fase1::inicializar()
{

}

void Fases::Fase1::criaInimFaceis()
{
}

void Fases::Fase1::criaEspinhos()
{
}

void Fases::Fase1::finalizar()
{

}