#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Entidade.h"
#include <iostream>
using namespace std;

//using namespace Entidades;
//class Entidade;

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
		//void desenharEntidade(Entidades::Entidade* pEntidade); //x
		void desenhar(sf::RectangleShape ret); 
		void fecharJanela();
        void desenhar(sf::Text texto);
		void desenhar(sf::Sprite sprite);
        sf::RenderWindow *getJanela(); 
        const bool janelaAberta() const;
		float getTamx();
		float getTamy();
		void limpaJanela();
		void mostrarJanela();
	};

}
