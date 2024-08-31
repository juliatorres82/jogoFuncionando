#include "../../../includes/Entidades/Obstaculos/Gosma.h"
#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h"


namespace Entidades::Obstaculos {

Gosma:: Gosma (int posx, int posy): viscosidade(0.5){
    corpo.setPosition(posx, posy);
    corpo.setFillColor(sf::Color::Red);
}

    Gosma:: ~Gosma() {}

    void Gosma::obstacular(Entidades::Personagens::Jogador *j1) {
        while(pGC->haColisao(this, j1))
            j1->setVelocidadex(j1->getVelocidadex()-1.5);
    }

    void Gosma::executar(){
        
        obstacular(jog1);
        if(jog2 != NULL)
            obstacular(jog2);
    }
}