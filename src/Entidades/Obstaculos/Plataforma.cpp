#include "../../../includes/Entidades/Obstaculos/Plataforma.h"

using namespace Entidades::Obstaculos;

Plataforma::Plataforma()
{
	id = plataForma;
	dimensoes.x = 20.0;
	dimensoes.y = 40.0;
	elasticidade = 0;
	corpo.setFillColor(sf::Color::Blue);
	setTam();
	setPosicao(0.f, 0.f);
	danoso = false;

}

Plataforma::Plataforma(sf::Vector2f posicao, int e, sf::Vector2f tam)
{
	pos = posicao;
	dimensoes = tam;
	setTam();
	setPosicao();
	setElasticidade(e);
	danoso = false;
}

Plataforma:: Plataforma(int x, int y) : elasticidade(0) {
	corpo.setPosition(x, y);
	corpo.setFillColor(sf::Color::Blue);
}


Plataforma::~Plataforma()
{
	pGG = nullptr;
}

void Plataforma::setElasticidade(int e)
{
	elasticidade = e;
}


void Plataforma::executar()
{
	obstacular();
	desenhar();
}

void Plataforma::obstacular()
{	
	cair();
	fazEmpuxo();
}

void Entidades::Obstaculos::Plataforma::fazEmpuxo() { //possibilita às plataformas flutuarem
	corpo.move(sf::Vector2f(0, -gravidade));
}
