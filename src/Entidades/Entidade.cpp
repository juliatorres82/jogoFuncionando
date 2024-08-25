#include "../../includes/Entidades/Entidade.h"
using namespace Entidades;

Entidade::Entidade() :
	corpo(sf::Vector2f(20.f, 40.f))
{
	tipo = estatico;
}

Entidade::~Entidade()
{
}

void Entidade::desenhar()
{
	pGG->desenhar(corpo);
}

void Entidade::setTam()
{
	sf::Vector2f v;
	v.x = 20.f;
	v.y = 40.f;
	
	corpo.setSize(v);
}

void Entidade::atualizar(){
	pos = corpo.getPosition();
}

float Entidade::getPosicaox()
{
	atualizar();
    return pos.x;
}

float Entidade::getPosicaoy()
{
	atualizar();
    return pos.y;
}

void Entidade::cair()
{
	corpo.move(sf::Vector2f(0, aCgravidade));
}

sf::RectangleShape& Entidade::getCorpo()
{
	return corpo;
}

const bool Entidade::ehDinamico() const
{
	return tipo == dinamico;
}

void Entidade::setPosicao(float x, float y)
{
	corpo.setPosition(sf::Vector2f(x, y));
}