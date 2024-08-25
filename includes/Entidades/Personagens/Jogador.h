#pragma once
#include "Inimigo.h"
#define velocidadeJogador 5.0f
#define pulo -100.0f

namespace Entidades
{
	namespace Personagens
	{
		class Jogador :
			public Personagem
		{
			private:
				int pontos;
				Jogador* jogador2;

			public:
				Jogador();
				Jogador(Jogador* j2);
				~Jogador();

				void executar();
				void mover();
				void Pular(); 
				void movDir();
				void movEsq();
				void setJogador2(Jogador* j2);
				Jogador* getJogador2();
				bool doisJogadores();
		};
	}
}

		

