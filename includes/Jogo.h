#pragma once
#include <iostream>
#include "Gerenciadores/Gerenciador_Eventos.h" 
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Gerenciadores/Gerenciador_Inputs.h"
class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
		Gerenciadores::Gerenciador_Eventos* gerenciador_eventos;
		Gerenciadores::Gerenciador_Inputs* gerenciador_inputs;
		Gerenciadores::Gerenciador_Estados* gerenciador_estados;
		Personagens::Jogador jogador1;
		Personagens::Jogador* jogador2;
		//Inimigo inimigo1;
		Fantasma fantasma1;
		Lagarto lagarto1;

		Plataforma plataforma1;
		Plataforma plataforma2;
		Plataforma plataforma3;

		PlataformaGelo platGelo;
		Gosma gosma1;
		Espinho espinho1;

		//Fase fase1;
		sf::RenderWindow* janela_jogo;

	public:
		Jogo();
		~Jogo();

		void Executar();
};
