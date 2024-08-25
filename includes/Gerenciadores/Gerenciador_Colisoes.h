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
		list<Entidades:: Obstaculos::Obstaculo*> lOS;
		Entidades::Personagens::Jogador* jog;

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
		void tratarColisoesInims();
		void tratarColisoes();
		bool colidindo();
		void resolverColisao(Entidade* p1, Entidade* p2, sf::FloatRect intersec);
	};
}

