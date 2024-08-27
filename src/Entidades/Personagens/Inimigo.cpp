//#include "../../../includes/Entidades/Personagens/Inimigo.h"
#include "../../../includes/Entidades/Personagens/Jogador.h"

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo() :
	nivel_maldade(0), jogador1(nullptr)
{
	id = idEntes::iniMigo;
	corpo.setFillColor(sf::Color::Red);
	pos = sf::Vector2f(100.f, 250.f);
	setPosicao(pos.x, pos.y);
	dimensoes = sf::Vector2f(40.0, 40.0);
	velx = velocidadeInimigo;
	setTam();
	vely = puloInimigo;
}

Inimigo:: Inimigo(float x, float y) {
	corpo.setPosition(sf::Vector2f(x, y));
	id = idEntes::iniMigo;
	corpo.setFillColor(sf::Color::Red);
	dimensoes = sf::Vector2f(40.0, 40.0);
	velx = velocidadeInimigo;
	setTam();
	vely = puloInimigo;

}

Inimigo::~Inimigo()
{
	jogador1 = nullptr;
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

void Inimigo::mover()
{
	if(getPosicaox() >= 0.0)
		corpo.move(-velx, vely);

	else 
		corpo.move(velx, vely);

	cair();
}
void Inimigo::executar()
{
	mover();
	desenhar();
}

void Inimigo::voltar()
{
	velx = velocidadeInimigo;
	vely = puloInimigo;
}