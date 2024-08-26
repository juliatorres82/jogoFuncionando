#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Ente;

namespace Gerenciadores
{
	class Gerenciador_Grafico
	{
	private:
		static Gerenciador_Grafico* instancia;
		sf::RenderWindow* janela;
		Gerenciador_Grafico(); 

	public:

		~Gerenciador_Grafico();
		static Gerenciador_Grafico* getInstancia();
		void desenharEnte(Ente* pEnte);
		void desenhar(sf::RectangleShape ret);
		void fecharJanela();
        void desenhar(sf::Text texto);
		void desenhar(sf::Sprite sprite);
        sf::RenderWindow *getJanela();
        const bool janelaAberta() const;
		float getTamx();
		float getTamy();
		void setJanela(sf::RenderWindow* jan);
	};



}
