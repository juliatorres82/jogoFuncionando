#pragma once
#include "Personagem.h"
#define velocidadeInimigo 2.0f
#define puloInimigo -20.0f

namespace Entidades
{
	namespace Personagens
	{
		class Jogador;
		
		class Inimigo : public Personagem
		{
			protected:
				int nivel_maldade;
				Jogador* jogador1;

			public:
				Inimigo();
				~Inimigo();

				void setMaldade(int m);
				void setJogador(Jogador* jog1);
				Jogador* getJogador1();
				virtual void executar();
				virtual void mover();
				void voltar();
		};
	}
}

	



