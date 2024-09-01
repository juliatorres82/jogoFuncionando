#include "../../includes/Entidades/Entidade.h"

using namespace Entidades;

Entidade::Entidade() :
	corpo(sf::Vector2f(40.f, 40.f))
{
	dimensoes = sf::Vector2f(0.f, 0.f);
	pos = sf::Vector2f(0.f, 0.f);
	tipo = estatico;
	gravidade = 0.0;
	caiu = false;
	colidindo = false;
	velox = 4.0;
}

Entidade::~Entidade()
{

}

void Entidade::desenhar(){
	pGG->desenhar(corpo);
}

void Entidade::desenhar(sf::Sprite& sprite){
	pGG->desenhar(sprite);
}

void Entidade::setTam()
{
	corpo.setSize(dimensoes);
}

void Entidade::atualizar() {
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
	if (tipo != estatico && gravidade <= velTerminal)
		gravidade += aCgravidade;

	if(caiu)
		gravidade = 0;

	corpo.move(sf::Vector2f(0.f, gravidade));
	if(colidindo && !caiu)
		corpo.move(sf::Vector2f(0.f, -2.f));
}

sf::RectangleShape& Entidade::getCorpo()
{
	return corpo;
}

sf::FloatRect Entidades::Entidade::getContorno() const
{
	return corpo.getGlobalBounds();
}

const bool Entidade::ehDinamico() const
{
	return (tipo == dinamico);
}

bool Entidades::Entidade::emColisao(const Entidade& outro, sf::FloatRect& intersec) const
{
	return (getContorno().intersects(outro.getContorno(), intersec));			
}

bool Entidades::Entidade::emColisao(const Entidade& outro) const
{
	return (getContorno().intersects(outro.getContorno()));
}

void Entidades::Entidade::mudaColidindo(bool flagColid)
{
	colidindo = flagColid;
}
void Entidade::mudaCaiu(bool queda)
{
	caiu = queda;
}
void Entidade::setPosicao()
{
	corpo.setPosition(pos);
}
void Entidade::setPosicao(float x, float y)
{
	pos.x = x;
	pos.y = y;

	corpo.setPosition(pos);
}

void Entidade:: setVelocidadex(float vel){
	velox = vel;
}

float Entidade:: getVelocidadex(){
	return velox;
}
