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
			sf::Vector2f pos; //x
			sf::Vector2f dimensoes; //x
			dinamismo tipo;
			float gravidade; // --> fis
			bool caiu;
			bool colidindo;
			float velx;

		public:
			Entidade();
			~Entidade();
			void desenhar(); 
			virtual void executar() = 0;
			void setTam(); //x
			sf::RectangleShape& getCorpo(); 
			sf::FloatRect getContorno() const;
			void atualizar();
			float getPosicaox();
			float getPosicaoy();
			const bool ehDinamico() const;
			bool emColisao(const Entidade& outro, sf::FloatRect& intersec) const; //x
			bool emColisao(const Entidade& outro) const; //x
			void mudaColidindo(bool flagColid);
			void mudaCaiu(bool queda);
			void setPosicao(float x, float y); //x
			void setPosicao(); //x
			void cair();
			void setVelocidadex (float vel);
			float getVelocidadex();
	};

}

