#include "../../../includes/Entidades/Personagens/Personagem.h"
using namespace Entidades::Personagens;

Personagem::Personagem():
	vidas(10), velx(0), vely(0)
{
	tipo = dinamico;
	colidindo = true;
	corpo.setPosition(sf::Vector2f(0.f, 0.f));
}

Personagem::~Personagem()
{
}

void Personagem::mover()
{
	pular(0);
}

void Personagem::pular(float pulo)
{
	if(colidindo)
		corpo.move(sf::Vector2f(0.f, pulo));

}

void Personagem::mudaColidindo(bool flagColid)
{
	colidindo = flagColid;
}
