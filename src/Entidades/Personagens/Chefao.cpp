#include "../../../includes/Entidades/Personagens/Chefao.h"
//#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h" 

Chefao::Chefao(float x, float y) : Inimigo(x,y) {
    atirar = false;
    projeteis = nullptr;
    pGC = pGC->getInstancia();
}


Chefao::~Chefao() {

   //if(projeteis != nullptr)
       // delete projeteis;
    projeteis = nullptr; 
}


void Chefao::atacar() {

    if( ! (pGC->haColisao(projeteis, jogador1) || pGC->haColisao(projeteis, jogador2)) ) 
    { //não há colisão com qualquer jogador
        sf::Vector2f posJogador(jogador1->getPosicaox(), jogador1->getPosicaoy());
        projeteis = new Projetil(corpo.getPosition(), sf::Vector2f(posJogador.x - corpo.getPosition().x, posJogador.y - corpo.getPosition().y), 2.0f);
        projeteis->desenhar();
    }

    else
    {
        projeteis->parar();
        delete projeteis;
    }
}

void Chefao:: executar(){
    atacar();
}