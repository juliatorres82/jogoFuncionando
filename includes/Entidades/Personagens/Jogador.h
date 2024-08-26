#pragma once
#include "Inimigo.h"
#define velocidadeJogador 5.0f
#define pulo -20.0f

enum qJogador
{
	jg1, jg2
};

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
			qJogador qJog;

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
			void setQJog();
			void voltar();
		};
	}
}


		

