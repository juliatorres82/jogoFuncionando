#include "../../../includes/Entidades/Personagens/Jogador.h"
using namespace Entidades::Personagens;

Entidades::Personagens::Jogador::Jogador(Jogador* j2) :
	pontos(0), jogador2(j2)
{
	id = idEntes::jogaDor;
	velx = velocidadeJogador;
	vely = pulo;
	corpo.setPosition(sf::Vector2f(200.f, 100.f));
	corpo.setFillColor(sf::Color::Green);
}

Entidades::Personagens::Jogador::Jogador() :
	pontos(0), jogador2(NULL)
{
	id = idEntes::jogaDor;
	velx = velocidadeJogador;
	vely = pulo;
	corpo.setPosition(sf::Vector2f(200.f, 100.f));
	corpo.setFillColor(sf::Color::Green);
}

Entidades::Personagens::Jogador::~Jogador()
{
	jogador2 = NULL;
}

void Entidades::Personagens::Jogador::Pular()
{

	pular(vely);

}


void Entidades::Personagens::Jogador::movDir()
{
	corpo.move(sf::Vector2f(velx, 0.f));
}


void Entidades::Personagens::Jogador::movEsq()
{
	corpo.move(sf::Vector2f((-1)*velx, 0.f));
}


void Entidades::Personagens::Jogador:: setJogador2(Jogador* j2){
	jogador2 = j2;
}


Jogador* Entidades::Personagens::Jogador:: getJogador2(){

	return jogador2;
}


bool Entidades::Personagens::Jogador:: doisJogadores(){
	if (jogador2 == NULL)
		return false;
	return true;
}


void Entidades::Personagens::Jogador::mover()
{

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velx = 0;
	}

	else
	{
		velx = velocidadeJogador;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			Pular();

		movDir();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			Pular();
		movEsq();
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Pular();
	
	cair();
}


void Entidades::Personagens::Jogador::executar()
{
	mover();
	desenhar();
}



