#include "../../../includes/Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades::Obstaculos;

Obstaculo::Obstaculo(bool daDano)
{
	tipo = estatico;
	id = idEntes::obsTaculo;
	danoso = daDano;
	jog1 = nullptr;
	jog2 = nullptr;
}


Obstaculo::~Obstaculo(){
	jog1 = nullptr;
	jog2 = nullptr;
}

const bool Entidades::Obstaculos::Obstaculo::ehDanoso() const
{
    return danoso;
}

void Entidades::Obstaculos::Obstaculo::setJogadorPDano(Jogador *j1){
	jog1 = j1;
	jog2 = j1->getJogador2();
}