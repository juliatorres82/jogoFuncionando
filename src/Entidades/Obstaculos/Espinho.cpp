#include "../../../includes/Entidades/Obstaculos/Espinho.h"


namespace Entidades::Obstaculos {

    Espinho::Espinho() {}

    Espinho:: Espinho(int posx, int posy){
        corpo.setPosition(posx, posy);
        corpo.setFillColor(sf::Color::Red);
    }

    Espinho:: ~Espinho() {}


    void Espinho:: obstacular(Entidades::Personagens::Jogador* j1){
        j1->setVidas(j1->getVidas()-1);
    }

    void Espinho::executar(){

        obstacular(jog1);
        if(jog2 != NULL)
            obstacular(jog2);
    }
}
