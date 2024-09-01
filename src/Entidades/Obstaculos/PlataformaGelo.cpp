#include "../../../includes/Entidades/Obstaculos/PlataformaGelo.h"
#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Entidades;
using namespace Obstaculos;

PlataformaGelo::PlataformaGelo(int posx, int posy): Obstaculo(false), deslizo(0.5) {
    corpo.setPosition(posx, posy);
    corpo.setFillColor(sf::Color::Yellow);
}

PlataformaGelo:: ~PlataformaGelo() {}

void PlataformaGelo::fazEmpuxo() {
    corpo.move(sf::Vector2f(0, -gravidade));
}

void PlataformaGelo:: executar() {
    cair();
    fazEmpuxo();
} 


void PlataformaGelo:: obstacular(Jogador* j1){

    while(pGC->haColisao(this, j1)){
        j1->setVelocidadex(j1->getVelocidadex()+1.5);
    }
    while(pGC->haColisao(this, j1->getJogador2())){
        j1->getJogador2()->setVelocidadex(j1->getJogador2()->getVelocidadex()+1.5);
    }
}

