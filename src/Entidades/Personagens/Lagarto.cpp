#include "../../../includes/Entidades/Personagens/Lagarto.h"

Lagarto:: Lagarto() : amplitude(10.0f){
    setVelocidadex(2.0f);
}


Lagarto:: Lagarto(float x, float y) : amplitude(10.0f){
    corpo.setPosition(sf::Vector2f(x, y));
    setVelocidadex(2.0f);
}


Lagarto:: ~Lagarto() {}


void Lagarto:: mover() {

    float dx = 0.0;

    while(pGG->janelaAberta()){ //----testar
        dx = getPosicaox();
        corpo.move(getVelocidadex(), 0);
        if(dx == amplitude || dx == -amplitude)
            setVelocidadex(-getVelocidadex()); 
    } 
}

void Lagarto:: executar() {
    mover();
    atacar();
}

void Lagarto:: atacar() { 
    if(pGC->haColisao(this, getJogador1())){ //mudar p ambos os jjogs 
        getJogador1()->setVidas(getJogador1()->getVidas()-1);
    }
}