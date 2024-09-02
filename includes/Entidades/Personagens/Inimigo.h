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
				Jogador* jogador2;

			public:
				Inimigo();
				Inimigo(float x, float y);
				virtual ~Inimigo();

				void setMaldade(int m);
				void setJogador(Jogador* jog1);

				int getMaldade();
				Jogador* getJogador1();
				virtual void executar();
				virtual void mover();
				void voltar();
                
        };
    }
}

	



