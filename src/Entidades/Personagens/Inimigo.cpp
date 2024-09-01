#include "../../../includes/Entidades/Personagens/Jogador.h"

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo() :
	nivel_maldade(0), jogador1(nullptr)
{
	jogador1 = NULL;
	jogador2 = NULL;
	id = idEntes::iniMigo;
	corpo.setFillColor(sf::Color::Red);
	pos = sf::Vector2f(100.f, 250.f);
	setPosicao(pos.x, pos.y);
	dimensoes = sf::Vector2f(40.0, 40.0);
	velx = velocidadeInimigo;
	setTam();
	vely = puloInimigo;
}

Inimigo:: Inimigo(int x, int y) {
	jogador1 = NULL;
	jogador2 = NULL;
	corpo.setPosition(x, y);
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
	jogador2 = nullptr;
}

void Inimigo::setMaldade(int m)
{
	nivel_maldade = m;
}

void Inimigo::setJogador(Jogador *jog1)
{
	jogador1 = jog1;
	if(jog1->doisJogadores()){
		jogador2 = jogador1->getJogador2();
	}
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
	atualizar();
}

void Inimigo::voltar()
{
	velx = velocidadeInimigo;
	vely = puloInimigo;
}

int Inimigo::getMaldade()
{
	return nivel_maldade;
}