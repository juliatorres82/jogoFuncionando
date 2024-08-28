#include "../../../includes/Entidades/Obstaculos/Espinho.h"

Espinho::Espinho() {}

Espinho:: Espinho(int posx, int posy){
    corpo.setPosition(posx, posy);
    corpo.setFillColor(sf::Color::Red);
}

Espinho:: ~Espinho() {}


void obstacular(Jogador* j1){
    j1->setVidas(j1->getVidas()-1);
}