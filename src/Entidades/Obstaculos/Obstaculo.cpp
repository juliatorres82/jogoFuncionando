#include "../../../includes/Entidades/Obstaculos/Obstaculo.h"
using namespace Entidades::Obstaculos;

Obstaculo::Obstaculo(bool daDano)
{
	tipo = estatico;
	id = idEntes::obsTaculo;
	danoso = daDano;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::empuxo()
{
	empuxo();
}

const bool Entidades::Obstaculos::Obstaculo::ehDanoso() const
{
    return danoso;
}
