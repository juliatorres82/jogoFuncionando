#include "../../../includes/Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades::Obstaculos;

Obstaculo::Obstaculo(bool daDano)
{
	tipo = estatico;
	id = idEntes::obsTaculo;
	danoso = daDano;
}


Obstaculo::~Obstaculo(){}

const bool Entidades::Obstaculos::Obstaculo::ehDanoso() const
{
    return danoso;
}

void Entidades::Obstaculos::Obstaculo::setJogadoresPDano(Jogador *j1, Jogador *j2){

}