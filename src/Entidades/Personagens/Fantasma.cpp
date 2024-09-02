#include "../../../includes/Entidades/Personagens/Fantasma.h"
#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h"

Fantasma :: Fantasma() : invisivel(false) {}


Fantasma :: Fantasma(float x, float y) {
    corpo.setPosition(sf::Vector2f(x, y));
} 

Fantasma :: ~Fantasma() {
    jogador1 = nullptr;
    jogador2 = nullptr;
}


void Fantasma:: assustar() {
    
    Jogador* jog1 = getJogador1(); 

    if(jog1){

        if(jog1->getPosicaox() - getPosicaox() < 2*jog1->getCorpo().getSize().x && jog1->getPosicaoy() - getPosicaoy() < 2*jog1->getCorpo().getSize().y){
            ficarVisivel();
        }
        else
            ficarInvisivel();
        if(getPosicaoy() > 0 && !colidindo)
            corpo.move(sf::Vector2f(0.f, vely));
        else if(!colidindo)
            corpo.move(sf::Vector2f(vely, 0.f));
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
    if(jogador1 != nullptr)
        assustar();
}

void Fantasma :: executar() {

    mover();
    atacar();
    atualizar();
}

void Fantasma :: atacar() {
    if(pGC->haColisao(this, getJogador1()))
        getJogador1()->setVidas(getJogador1()->getVidas()-1);
}

void Fantasma::desenhar()
{
    if(!invisivel)
        pGG->desenhar(corpo);
}

void Fantasma::flutuacao()
{
    corpo.move(0.f, -gravidade);
}
