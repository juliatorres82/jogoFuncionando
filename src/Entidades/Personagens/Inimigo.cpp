//#include "../../../includes/Entidades/Personagens/Inimigo.h"
#include "../../../includes/Entidades/Personagens/Jogador.h"

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo() :
	nivel_maldade(0), jogador1(NULL)
{
	id = idEntes::iniMigo;
	corpo.setFillColor(sf::Color::Red);
	corpo.setPosition(sf::Vector2f(10.f, 10.f));
	velx = 10;
	vely = 20;
}

Inimigo::~Inimigo()
{
	jogador1 = NULL;
}

void Inimigo::setMaldade(int m)
{
	nivel_maldade = m;
}

void Inimigo::setJogador(Jogador *jog1)
{
	jogador1 = jog1;
}

Jogador* Inimigo:: getJogador1() {

	return jogador1;
}

void Inimigo::executar()
{
	mover();
	desenhar();
}

