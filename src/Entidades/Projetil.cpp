#include "../../includes/Entidades/Projetil.h"
#include "../../includes/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Entidades;

Projetil:: Projetil(sf::Vector2f pos, float vel) : Entidade(), colidindo(false), direcao(0,0){
    velocidade = vel;
    pGC = pGC->getInstancia();
    pGC->incluirProjeteis(this);
    corpo.setSize(sf::Vector2f(3.0,2.0));

}

void Projetil:: setDirecao(sf::Vector2f dir){
    direcao = dir;
}

Projetil::~Projetil(){
    pGC = pGC->getInstancia();
    pGC->retiraProjetil(this);
}

sf::Vector2f Projetil:: getPosicao(){
    return corpo.getPosition();
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