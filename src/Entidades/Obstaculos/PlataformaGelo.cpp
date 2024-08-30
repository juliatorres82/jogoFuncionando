#include "../../../includes/Entidades/Obstaculos/PlataformaGelo.h"
#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Entidades;
using namespace Obstaculos;

PlataformaGelo::PlataformaGelo(){}


PlataformaGelo::PlataformaGelo(int posx, int posy) {
    corpo.setPosition(posx, posy);
    corpo.setFillColor(sf::Color::Yellow);
}


PlataformaGelo:: ~PlataformaGelo() {}


void PlataformaGelo:: executar() {} //implemetar; fiz assim só p compilar


void PlataformaGelo:: obstacular(Jogador* j1){

    while(pGC->haColisao(this, j1)){
        j1->setVelocidadex(j1->getVelocidadex()+1.5);
    }
    while(pGC->haColisao(this, j1->getJogador2())){
        j1->getJogador2()->setVelocidadex(j1->getJogador2()->getVelocidadex()+1.5);
    }
}