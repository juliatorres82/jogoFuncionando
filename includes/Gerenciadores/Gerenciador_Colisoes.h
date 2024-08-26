#pragma once
#include "../Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
#include <list>

namespace Gerenciadores
{

	class Gerenciador_Colisoes
	{
	private:
		vector<Inimigo*> lIs;
		list<Entidades::Obstaculos::Obstaculo*> lOS;
		vector<Jogador*> jogs;

		Gerenciador_Colisoes();
		static Gerenciador_Colisoes* instancia;
	public:
		~Gerenciador_Colisoes();
		static Gerenciador_Colisoes* getInstancia();
		void incluirObstaculos(Entidades::Obstaculos::Obstaculo* pO);
		void incluirInimigos(Entidades::Personagens::Inimigo* pI);
		void incluirJogador(Entidades::Personagens::Jogador* pJ);
		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInims();
		void tratarColisoesInimsObstacs();
		void tratarColisoes();
		void resolverColisao(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
		void resolverColisaoComDin(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
		void resolverColisaoComEstat(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
	};
}