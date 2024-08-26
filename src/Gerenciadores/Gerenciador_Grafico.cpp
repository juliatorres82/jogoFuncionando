#include "../../includes/Gerenciadores/Gerenciador_Grafico.h"
#include "../../includes/Ente.h"

using namespace Gerenciadores;


Gerenciador_Grafico* Gerenciador_Grafico::instancia = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico()
{
	janela = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Jogo", sf::Style::Fullscreen);
	janela->setFramerateLimit(60);	
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	if (janela != nullptr) 
	{			
		delete janela;
		janela = nullptr;
	}	
}

Gerenciador_Grafico* Gerenciador_Grafico::getInstancia()
{
	if (instancia == nullptr)
	{
		instancia = new Gerenciador_Grafico();
	}

	return instancia;
}

void Gerenciador_Grafico::desenharEnte(Ente* pEnte)
{
	pEnte->desenhar();
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape ret)
{
	janela->draw(ret);
}

void Gerenciadores::Gerenciador_Grafico::fecharJanela()
{
	janela->close();
}

sf::RenderWindow *Gerenciador_Grafico::getJanela()
{
	return janela;
}

const bool Gerenciadores::Gerenciador_Grafico::janelaAberta() const
{
	return janela->isOpen();
}

float Gerenciador_Grafico::getTamx()
{
	return janela->getSize().x;
}

float Gerenciador_Grafico::getTamy()
{
	return janela->getSize().y;
}

void Gerenciador_Grafico:: setJanela(sf::RenderWindow* jan){

	janela = jan;
}
