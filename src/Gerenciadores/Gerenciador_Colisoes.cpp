#include "../../includes/Gerenciadores/Gerenciador_Colisoes.h"

using namespace Gerenciadores;

Gerenciador_Colisoes* Gerenciador_Colisoes::instancia = nullptr;

Gerenciador_Colisoes::Gerenciador_Colisoes()
{
	lIs.clear();
	lOS.clear();
	jogs.clear();

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	lIs.clear();
	lOS.clear();
	jogs.clear();
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
	jogs.push_back(pJ);
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
	
	for (auto& inimigo : lIs)
	{
		sf::FloatRect intersec;
		for (auto& jog : jogs)
		{
			if (jog == nullptr)
			{
				return;
			}
			if (jog->getCorpo().getGlobalBounds().intersects(inimigo->getCorpo().getGlobalBounds(), intersec))
			{
				jog->mudaColidindo(true);
				inimigo->mudaColidindo(true);
				jog->parar();
				inimigo->parar();
				resolverColisao(static_cast<Entidade*>(jog), static_cast<Entidade*>(inimigo), intersec);
				jog->voltar();
				inimigo->voltar();
			}
		}
	}

}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesInimsObstacs()
{
	for (auto& inimigo : lIs)
	{
		inimigo->mudaColidindo(false);
		inimigo->mudaCaiu(false);
		sf::FloatRect intersec;
		for (auto& obstaculo : lOS)
		{
			if (inimigo->getCorpo().getGlobalBounds().intersects(obstaculo->getCorpo().getGlobalBounds(), intersec))
			{
				inimigo->parar();
				inimigo->mudaColidindo(true);
				resolverColisao(static_cast<Entidade*>(inimigo), static_cast<Entidade*>(obstaculo), intersec);
				inimigo->voltar();
			}
		}
	}
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
	for (auto& jog : jogs)
	{
		
		if (jog != nullptr)
		{
			sf::FloatRect intersec;
			jog->mudaColidindo(false);
			jog->mudaCaiu(false);
			for (auto& obstaculo : lOS)
			{
				if ((jog->getCorpo().getGlobalBounds().intersects(obstaculo->getCorpo().getGlobalBounds(), intersec))) //se há interseção
				{
					jog->mudaColidindo(true);
					jog->parar();
					obstaculo->obstacular(jog); 
					resolverColisao(static_cast<Entidade*>(jog), static_cast<Entidade*>(obstaculo), intersec);
					jog->voltar();
				}
			}
		}
	}
}


void Gerenciadores::Gerenciador_Colisoes::tratarColisoes()
{
	tratarColisoesJogsObstacs();
	tratarColisoesInimsObstacs();
	tratarColisoesJogsInims();
}

void Gerenciador_Colisoes::resolverColisao(Entidade* p1, Entidade* p2, sf::FloatRect intersec) {

	if (p1->ehDinamico() && !p2->ehDinamico())
	{
		resolverColisaoComEstat(p1, p2, intersec);
	}

	else if (p1->ehDinamico() && p2->ehDinamico())
	{
		resolverColisaoComDin(p1, p2, intersec);
	}
}

void Gerenciadores::Gerenciador_Colisoes::resolverColisaoComDin(Entidade* p1, Entidade* p2, sf::FloatRect intersec)
//caso em que p1 e p2 estão em movimento
{
	sf::FloatRect ret1 = p1->getCorpo().getGlobalBounds();	
	sf::FloatRect ret2 = p2->getCorpo().getGlobalBounds();

	float tamHorizontal = intersec.width;
	float tamVertical = intersec.height;
	bool pelaEsquerda = ret1.left < ret2.left; //p1 colide à esquerda de p2
	bool deCima = ret1.top > ret2.top; //p1 colide acima de p2

	if (tamHorizontal < tamVertical) { //se for colisão horizontal, cada um vai para trás
		p1->getCorpo().move(pelaEsquerda ? -tamHorizontal : tamHorizontal, 0.f);
		p2->getCorpo().move(pelaEsquerda ? tamHorizontal : -tamHorizontal, 0.f);
	}
	else //colisão vertical
	{	
		Personagem* aux = nullptr;
		Personagem* aux2 = nullptr;
		//se a colisão foi de p1 por cima de p2, então: aux1 = p2, aux2 = p1;
		deCima ? aux = static_cast<Personagem*>(p2),aux2 = static_cast<Personagem*>(p1): aux = static_cast<Personagem*>(p1), aux2 = static_cast<Personagem*>(p2);
		aux->mudaPodePular(true);
		aux->mudaCaiu(true);
		aux2->mudaCaiu(true);

		p1->getCorpo().move(0.f, deCima ? tamVertical : -tamVertical); //move verticalmente o mesmo tamanho da intersecção vertical
		aux = nullptr;
	}
}

void Gerenciadores::Gerenciador_Colisoes::resolverColisaoComEstat(Entidade* p1, Entidade* p2, sf::FloatRect intersec) 
//caso em que p1 se move e p2 está parado
{
	sf::FloatRect ret1 = p1->getCorpo().getGlobalBounds();
	sf::FloatRect ret2 = p2->getCorpo().getGlobalBounds();

	float tamLateral = intersec.width;
	float tamVertical = intersec.height;

	bool pelaEsquerda = ret1.left < ret2.left;
	bool deCima = ret1.top > ret2.top;

	if (tamLateral < tamVertical) {
		p1->mudaCaiu(true);
		p1->getCorpo().move(pelaEsquerda ? -tamLateral : tamLateral, 0.f);
	}
	else
	{	
		Personagem* aux = static_cast<Personagem*>(p1);
		aux->mudaPodePular(true);
		aux->mudaCaiu(true);
		if (deCima)
		{
			aux->mudaPodePular(false);
		}
		p1->getCorpo().move(0.f, deCima ? tamVertical : -tamVertical);
	}
}

bool Gerenciadores::Gerenciador_Colisoes:: haColisao(Entidade* p1, Entidade* p2) {
	return p1->getContorno().intersects(p2->getContorno());
}