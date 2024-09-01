#include "../../includes/Entidades/Projetil.h"

using namespace Entidades;

Projetil:: Projetil(sf::Vector2f pos, sf::Vector2f dir, float vel) : Entidade(), colidindo(false){
    direcao = dir;
    velocidade = vel;
    //pGC = pGC->getInstancia();
    //pGC->incluirProjetil(this);
    corpo.setSize(sf::Vector2f(3.0,2.0));

}


Projetil::~Projetil(){
   // pGC = pGC->getInstancia();
    //pGC->removerProjetil(this);
}


void Projetil::mover(){
    corpo.move(direcao * velocidade);
    cair();
}


void Projetil::parar(){
    velocidade = 0.0;
}

int Projetil:: causarDano(){
    return dano;
}

void Projetil::desenhar(){
    pGG->desenhar(corpo);
}

void Projetil::executar(){
    desenhar();
    mover();
}