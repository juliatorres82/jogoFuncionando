#include "../../includes/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Gerenciadores;

Gerenciador_Colisoes* Gerenciador_Colisoes::instancia = nullptr;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
	jog = nullptr;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	jog = nullptr;
}

Gerenciador_Colisoes* Gerenciador_Colisoes::getInstancia()
{
	if (instancia == nullptr)
	{
		instancia = new Gerenciador_Colisoes();
	}

	return instancia;

}

void Gerenciador_Colisoes::incluirJogador(Entidades::Personagens::Jogador* pJ)
{
	jog = pJ;
}

void Gerenciador_Colisoes::incluirObstaculos(Entidades::Obstaculos::Obstaculo* pO)
{
	lOS.push_back(pO);
}

void Gerenciador_Colisoes::incluirInimigos(Entidades::Personagens::Inimigo* pI)
{
	lIs.push_back(pI);
}

void Gerenciador_Colisoes::tratarColisoesJogsInims()
{
	sf::FloatRect ret1 = jog->getCorpo().getGlobalBounds();
	sf::FloatRect ret2 = lIs[0]->getCorpo().getGlobalBounds();
	sf::FloatRect intersec;

	if (jog == nullptr)
	{
		return;
	}
	if (ret1.intersects(ret2, intersec))
	{		
		resolverColisao(static_cast<Entidade*>(jog), static_cast<Entidade*>(lIs[0]), intersec);
	}
	
}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesInimsObstacs()
{
	for (auto& inimigo : lIs)
	{
		for (auto& obstaculo : lOS)
		{
			sf::FloatRect intersec;
			if (inimigo->getCorpo().getGlobalBounds().intersects(obstaculo->getCorpo().getGlobalBounds(), intersec))
			{
				resolverColisao(static_cast<Entidade*>(inimigo), static_cast<Entidade*>(obstaculo), intersec);
			}
		}
	}
}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesInims()
{
	for (auto& inimigo : lIs)
	{
		for (auto& inimigo2 : lIs)
		{
			if (inimigo != inimigo2)
			{


				sf::FloatRect intersec;
				if (inimigo->getCorpo().getGlobalBounds().intersects(inimigo2->getCorpo().getGlobalBounds(), intersec))
				{
					resolverColisao(static_cast<Entidade*>(inimigo), static_cast<Entidade*>(inimigo2), intersec);
				}
			}

		}
	}
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
	if (jog == nullptr)
	{
		return;
	}
	jog->mudaColidindo(false);

	for (auto& obstaculo : lOS)
	{
		sf::FloatRect intersec;
		if (jog->getCorpo().getGlobalBounds().intersects(obstaculo->getCorpo().getGlobalBounds(), intersec))
		{
			jog->mudaColidindo(true);
			resolverColisao(static_cast<Entidade*>(jog), static_cast<Entidade*>(obstaculo), intersec);
		}

	}
}


void Gerenciadores::Gerenciador_Colisoes::tratarColisoes()
{
	tratarColisoesJogsObstacs();
	tratarColisoesJogsInims();
	tratarColisoesInimsObstacs();
	tratarColisoesInims();
}

void Gerenciador_Colisoes::resolverColisao(Entidade* p1, Entidade* p2, sf::FloatRect intersec) {
	sf::FloatRect ret1 = p1->getCorpo().getGlobalBounds();
	sf::FloatRect ret2 = p2->getCorpo().getGlobalBounds();

	float movimentoLateral = intersec.width;
	float movimentoVertical = intersec.height;

	bool pelaEsquerda = ret1.left < ret2.left;
	bool deCima = ret1.top < ret2.top;
	
		if (movimentoLateral < movimentoVertical) {
			p1->getCorpo().move(pelaEsquerda ? -movimentoLateral : movimentoLateral, 0.f);
		}
		else
		{
			p1->getCorpo().move(0.f, deCima ? -movimentoVertical : movimentoVertical);
		}
}