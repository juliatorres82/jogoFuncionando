#pragma once

#include "../../Entidades/Personagens/Jogador.h"

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
				virtual void obstacular() = 0;
				void empuxo();
				const bool ehDanoso() const;

		};
	}
}

