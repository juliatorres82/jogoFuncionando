#include "../../../includes/Entidades/Obstaculos/Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	dimensoes.x = 20.0;
	dimensoes.y = 40.0;

	corpo.setFillColor(sf::Color::Blue);
	corpo.setSize(dimensoes);
	corpo.setPosition(300.0, 300.0);
	danoso = false;

	id = plataForma;
	//desenhar();
	//windowEnt->draw(shape);
}
Plataforma::Plataforma(sf::Vector2f posicao, int e, sf::Vector2f tam)
{
	dimensoes = tam;
	corpo.setSize(dimensoes);
	corpo.setPosition(posicao);
	setElasticidade(e);
	danoso = false;
}
Plataforma::~Plataforma()
{
	pGG = NULL;
}

void Plataforma::setElasticidade(int e)
{
	elasticidade = e;
}

void Plataforma::executar()
{
	obstacular();
}

void Plataforma::obstacular()
{
	empuxo();
}