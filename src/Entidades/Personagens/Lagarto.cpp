#include "../../../includes/Entidades/Personagens/Lagarto.h"
#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h"
Lagarto:: Lagarto() : amplitude(200.0f){
    setVelocidadex(2.0f);
    //amplitude = 100.0f;
}


Lagarto:: Lagarto(float x, float y) : amplitude(200.0f){
    corpo.setPosition(sf::Vector2f(x, y));
    setVelocidadex(2.0f);
    posInicialx = x;
}


Lagarto:: ~Lagarto() {
    jogador1 = nullptr;
    jogador2 = nullptr;
}


void Lagarto:: mover() {

    /*float dx = 0.0;
        dx = getPosicaox();
        corpo.move(getVelocidadex(), 0);
        if(dx >= amplitude || dx <= -amplitude){
            setVelocidadex(-getVelocidadex()); 
            cout << "mudou direcao" << endl;
        }
    */
   
    float deslocamentoRelativo = getPosicaox() - posInicialx;

    if (deslocamentoRelativo >= amplitude || deslocamentoRelativo <= -amplitude) {
        setVelocidadex(-getVelocidadex()); 
    }

    corpo.move(getVelocidadex(), 0);

    cair();
}


void Lagarto:: executar() {
    mover();
    //atacar();
    atualizar();
}


void Lagarto:: atacar() { 

    if(pGC->haColisao(this, getJogador1()))
        getJogador1()->setVidas(getJogador1()->getVidas()-1); //vidas-- quando toca o jogador 1
    
    else if (pGC->haColisao(this, getJogador1()->getJogador2()))
        (getJogador1()->getJogador2())->setVidas((getJogador1()->getJogador2())->getVidas()-1); //vida-- quando toca o jogador 2
    
}