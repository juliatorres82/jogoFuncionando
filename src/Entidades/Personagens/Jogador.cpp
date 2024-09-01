#include "../../../includes/Entidades/Personagens/Jogador.h"
#include "../../../includes/Observadores/ObservadorJog.h"

using namespace Entidades::Personagens;

Entidades::Personagens::Jogador::Jogador(Jogador* j2) :
	pontos(0), jogador2(j2), vidas(10)
{
	id = idEntes::jogaDor;
	velx = velocidadeJogador;
	vely = pulo;
	pos = sf::Vector2f(200.f, 100.f);
	setPosicao();
	corpo.setFillColor(sf::Color::Green);
	dimensoes = sf::Vector2f(40.f, 40.f);
	setTam();
	setQJog();
	observadorJog = new Observadores::ObservadorJog(this);
}

Entidades::Personagens::Jogador::Jogador() :
	pontos(0), jogador2(nullptr), vidas(10)
{
	setQJog();
	id = idEntes::jogaDor;
	velx = velocidadeJogador;
	vely = pulo;
	corpo.setPosition(sf::Vector2f(200.f, 100.f));
	corpo.setFillColor(sf::Color::Green);
	observadorJog = new Observadores::ObservadorJog(this);
}

Entidades::Personagens::Jogador:: Jogador(float x, float y): vidas(10){
	corpo.setPosition(sf::Vector2f(x, y));
	setQJog();
	id = idEntes::jogaDor;
	velx = velocidadeJogador;
	vely = pulo;
	corpo.setFillColor(sf::Color::Green);
	observadorJog = new Observadores::ObservadorJog(this);
}

Entidades::Personagens::Jogador::~Jogador()
{
	jogador2 = nullptr;
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
	corpo.move(sf::Vector2f((-1) * velx, 0.f));
}

Entidades::Personagens::Jogador* Entidades::Personagens::Jogador::getJogador2()
{
	return jogador2;
}

bool Entidades::Personagens::Jogador::doisJogadores() {
	if (jogador2 == nullptr)
		return false;
	return true;
}

void Entidades::Personagens::Jogador::setQJog()
{
	if(doisJogadores())
		qJog = jg2;
}

const qJogador Entidades::Personagens::Jogador::getQJog() const
{
    return qJog;
}

void Entidades::Personagens::Jogador::mover()
{
	cair();
}
void Entidades::Personagens::Jogador::executar()
{
	if(vidas <= 0)
	{
		if(observadorJog->getEstadoAtivo())
			observadorJog->mudaEstadoAtivo();
	}

	else if(!observadorJog->getEstadoAtivo())
	{
		observadorJog->mudaEstadoAtivo();
	}

	mover();
	desenhar();
}

void Entidades::Personagens::Jogador::setJogador2(Jogador* j2)
{
	if (jogador2 == nullptr)
		jogador2 = j2;
}

void Entidades::Personagens::Jogador::voltar()
{
	velx = velocidadeJogador;
	vely = pulo;
}

void Entidades::Personagens::Jogador::setVidas(int vidaNova){
	vidas = vidaNova;
}

int Entidades::Personagens::Jogador::getVidas(){
	return vidas;
}

void Entidades::Personagens::Jogador::resetaVelocidade()
{
	velx = velocidadeJogador;
}

void Entidades::Personagens::Jogador::mudaAtivo()
{
	if(observadorJog->getEstadoAtivo())
		observadorJog->mudaEstadoAtivo();
}
