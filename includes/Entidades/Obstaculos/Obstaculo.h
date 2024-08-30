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
				Jogador* jog1; //causam dano em;
				Jogador* jog2;

			public:
				Obstaculo(bool daDano = false);
				~Obstaculo();

				virtual void executar() = 0;
				virtual void obstacular(Jogador* jogad) = 0;
				const bool ehDanoso() const;
				void setJogadoresPDano(Jogador* j1, Jogador* j2 = NULL);

		};
	}
}

