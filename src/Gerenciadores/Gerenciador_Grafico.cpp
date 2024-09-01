#include "../../includes/Gerenciadores/Gerenciador_Grafico.h"

using namespace Gerenciadores;


Gerenciador_Grafico* Gerenciador_Grafico::instancia = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico()
{
	janela = new sf::RenderWindow(sf::VideoMode(960, 640), "Jogo", sf::Style::Default);
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

/*void Gerenciador_Grafico::desenharEntidade(Entidades::Entidade* pEntidade)
{
	janela->draw(pEntidade->getCorpo());

}*/

void Gerenciador_Grafico::desenhar(sf::RectangleShape ret)
{
	janela->draw(ret);
}

void Gerenciador_Grafico::desenhar(sf::Sprite sprite)
{
	janela->draw(sprite);
}

void Gerenciador_Grafico::desenhar(sf::Text texto)
{
	janela->draw(texto);
}
void Gerenciadores::Gerenciador_Grafico::fecharJanela()
{
	if(janela->isOpen())
		janela->close();
}

void Gerenciador_Grafico::desenhar(sf::Texture textura)
{
	sf::Sprite sprite;
	sprite.setTexture(textura);
	janela->draw(sprite);
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

void Gerenciador_Grafico::limpaJanela()
{
	janela->clear();
}

void Gerenciador_Grafico::mostrarJanela()
{
	janela->display();
}

