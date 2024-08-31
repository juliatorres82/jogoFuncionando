#include "../../../includes/Entidades/Obstaculos/Plataforma.h"
using namespace Entidades::Obstaculos;

Plataforma::Plataforma():
	elasticidade(0.0)
{
	id = plataForma;
	dimensoes.x = 20.0;
	dimensoes.y = 40.0;
	corpo.setFillColor(sf::Color::Blue);
	setTam();
	setPosicao(0.f, 0.f);
	danoso = false;
	//desenhar();
	//windowEnt->draw(shape);
}
Plataforma::Plataforma(sf::Vector2f posicao, int e, sf::Vector2f tam):
	elasticidade(e)
{
	pos = posicao;
	dimensoes = tam;
	setTam();
	setPosicao();
	danoso = false;
}
Plataforma::~Plataforma()
{
	pGG = nullptr;
}

void Plataforma::executar()
{
	obstacular();
	desenhar();
}

void Plataforma::obstacular()
{	
	cair();
	empuxo();
}