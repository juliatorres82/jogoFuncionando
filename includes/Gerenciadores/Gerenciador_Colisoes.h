#pragma once
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Entidade.h"
#include <list>
#include <vector>

using namespace Entidades;
using namespace Entidades::Obstaculos;

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
		void limpar();
		
		static Gerenciador_Colisoes* getInstancia();
		void incluirObstaculos(Obstaculo* pO);
		void incluirInimigos(Inimigo* pI);
		void incluirJogador(Jogador* pJ);


		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInims();
		void tratarColisoesInimsObstacs();
		void tratarColisoes();
		void resolverColisao(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
		void resolverColisaoComDin(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
		void resolverColisaoComEstat(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
		bool haColisao (Entidade* p1, Entidade* p2);
    };
}