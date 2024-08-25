#pragma once
#include <SFML/Graphics.hpp>
#include "../Ente.h"
#define aCgravidade 10.f
enum dinamismo 
{ estatico, dinamico };

namespace Entidades
{
	class Entidade : public Ente
	{
		protected:
			sf::RectangleShape corpo;
			sf::Vector2f pos;
			sf::Vector2f dimensoes;
			dinamismo tipo;

		public:
			Entidade();
			~Entidade();
			void desenhar();
			virtual void executar() = 0;
			void setTam();
			sf::RectangleShape& getCorpo();
			void atualizar();
			float getPosicaox();
			float getPosicaoy();
			const bool ehDinamico() const;
			void setPosicao(float x, float y);
			void cair();
	};

}



