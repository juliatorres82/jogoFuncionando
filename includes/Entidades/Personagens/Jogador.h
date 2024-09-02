#pragma once
#include "Inimigo.h"
#define velocidadeJogador 10.0f
#define pulo -100.0f

enum qJogador
{
	jg1, jg2
};

namespace Observadores
{
    class ObservadorJog;
}

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
			Observadores::ObservadorJog* observadorJog;

		public:
			Jogador(float x, float y);
			~Jogador();
			int vidas;


			void executar();
			void mover();
			void Pular();
			void movDir();
			void movEsq();
			void setJogador2(Jogador* j2);
			Jogador* getJogador2();
			bool doisJogadores();
			void setQJog();
			const qJogador getQJog() const;
			void voltar();
			void setVidas(int vidaNova);
			int getVidas();
            void resetaVelocidade();
            void mudaAtivo();
        };
    }
}


		

