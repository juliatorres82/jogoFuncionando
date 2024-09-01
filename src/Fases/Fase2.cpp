#include "../../includes/Fases/Fase2.h"

using namespace Fases;

Fase2::Fase2(bool coop) : Fase(coop) {
    caminho = "../elGrandeMapo.tmj";
    setCaminho(caminho);
    criaFundo();
    constroiFase();
}

Fase2::~Fase2() {
}

void Fase2::setCaminho(std::string caminhoArq) {
    caminho = caminhoArq;
}

void Fase2::atualizar() {
    listaJogadores->executaLista();
    listaInimigos->executaLista();
    listaObstaculos->executaLista();
    listaPlataforma->executaLista();
}

void Fase2::desenhar() {
    pGG->desenhar(fundo);
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}

/*
void Fases::Fase1::desenhar(){ //com sprites:
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}
*/