#include "../../../includes/Entidades/Personagens/Lagarto.h"

Lagarto:: Lagarto() : jog1(NULL){}

Lagarto:: Lagarto(float x, float y) {
    jog1 = NULL;
    corpo.setPosition(sf::Vector2f(x, y));
}

Lagarto:: ~Lagarto() {}

void Lagarto:: perseguir () {
    
     Jogador* jog1 = getJogador1();

    if(jog1){

        if(jog1->getPosicaox() - getPosicaox() > 0.0 ){ //jogador à frente do inimigo em x;
            corpo.move(velx, 0.0); 
        }

        else if (jog1->getPosicaox() - getPosicaox() < 0.0 )
            corpo.move(-velx, 0.0);

        if(jog1->getPosicaoy() - getPosicaoy() > 0.0 ) //jogador acima do inimigo;
            corpo.move(0.0, -vely);

        else if(jog1->getPosicaoy() - getPosicaoy() < 0.0 )
            corpo.move(0.0, vely);
    }

    else 
        cout << " Não foi setado nenhum jogador para perseguição " << endl;
}

void Lagarto:: mover() {
    perseguir();
}

void Lagarto:: executar() {
    mover();
}