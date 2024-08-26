#pragma once
#include <SFML/Graphics.hpp>
#include "../Ente.h"
#define aCgravidade 4.f
#define velTerminal 20.f

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
			float gravidade;
			bool caiu;
			bool colidindo;

		public:
			Entidade();
			~Entidade();
			void desenhar();
			virtual void executar() = 0;
			void setTam();
			sf::RectangleShape& getCorpo();
			sf::FloatRect getContorno() const;
			void atualizar();
			float getPosicaox();
			float getPosicaoy();
			const bool ehDinamico() const;
			bool emColisao(const Entidade& outro, sf::FloatRect& intersec) const;
			bool emColisao(const Entidade& outro) const;
			void mudaColidindo(bool flagColid);
			void mudaCaiu(bool queda);
			void setPosicao(float x, float y);
			void setPosicao();
			void cair();
	};

}

