#pragma once

#include "../../Entidades/Personagens/Jogador.h"

using namespace Entidades::Personagens;

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo: public Entidade
		{
			protected:
				bool danoso;

			public:
				Obstaculo(bool daDano = false);
				~Obstaculo();

				virtual void executar() = 0;
				virtual void obstacular(Jogador* jogad) = 0;
				void empuxo();
				const bool ehDanoso() const;

		};
	}
}

