#include "../../../includes/Entidades/Obstaculos/Espinho.h"

namespace Entidades::Obstaculos {

    Espinho:: Espinho(int posx, int posy): Obstaculo(true), danoEspinhar(1){
        corpo.setPosition(posx, posy);
        corpo.setFillColor(sf::Color::Yellow);
    }


    Espinho:: ~Espinho() {
        jog1 = nullptr;
        jog2 = nullptr;
    }


    void Espinho:: obstacular(Entidades::Personagens::Jogador* j1){
        j1->setVidas(j1->getVidas()-1);
    }

    void Espinho::executar(){

        obstacular(jog1);
        if(jog2 != NULL)
            obstacular(jog2);
    }
}
