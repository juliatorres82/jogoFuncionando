#include "../../../includes/Entidades/Obstaculos/Gosma.h"


Gosma:: Gosma() {}

Gosma:: Gosma (int posx, int posy){
    corpo.setPosition(posx, posy);
    corpo.setFillColor(sf::Color::Red);
}

Gosma:: ~Gosma() {}

void Gosma:: obstacular(Jogador* j1){
    while(pGC->haColisao(this, j1))
        j1->setVelocidadex(j1->getVelocidadex()-1.5);
}