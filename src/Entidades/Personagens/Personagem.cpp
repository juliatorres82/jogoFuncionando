#include "../../../includes/Entidades/Personagens/Personagem.h"
using namespace Entidades::Personagens;
Personagem::Personagem() : velx(0), vely(0)
{
	podePular = true;
	tipo = dinamico;
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Personagem::Personagem(float x, float y) : velx(0), vely(0)
{
	podePular = true;
	tipo = dinamico;
	corpo.setPosition(sf::Vector2f(x, y));
}

Personagem::~Personagem()
{
}

void Personagem::mover()
{
	pular(0);
}

void Personagem::pular(float puloo)
{
	if (colidindo && podePular)
		corpo.move(sf::Vector2f(0.f, puloo));
}

void Personagem::mudaPodePular(bool flagPodePular)
{
	podePular = flagPodePular;
}

void Personagem::parar()
{
	velx = 0;
	vely = 0;
}