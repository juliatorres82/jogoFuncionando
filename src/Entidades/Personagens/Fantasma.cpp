#include "../../../includes/Entidades/Personagens/Fantasma.h"

Fantasma :: Fantasma() : invisivel(false) {}


Fantasma :: Fantasma(float x, float y) {
    corpo.setPosition(sf::Vector2f(x, y));
} 

Fantasma :: ~Fantasma() {}


void Fantasma:: perseguir() {
    
    Jogador* jog1 = getJogador1();

    if(jog1){

        if(jog1->getPosicaox() - getPosicaox() < 2*jog1->getCorpo().getSize().x && jog1->getPosicaoy() - getPosicaoy() < 10.0){
            ficarVisivel();
        }
        else
            ficarInvisivel();
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


void Fantasma :: ficarInvisivel() {

    invisivel = true;

}

void Fantasma :: ficarVisivel() {

    invisivel = false;
}

bool Fantasma :: isInvisivel() {

    return invisivel;
}

void Fantasma :: mover() {

    perseguir();
}

void Fantasma :: executar() {

    mover();
    if(!invisivel)
        desenhar();
}
