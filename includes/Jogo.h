#pragma once
#include <iostream>
#include "Entidades/Obstaculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Eventos.h" 
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Entidades/Personagens/Fantasma.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

class Jogo
{
	private:
		Gerenciador_Grafico* gerenciador_grafico;
		Gerenciador_Colisoes* gerenciador_colisoes; // Fix the class name
		Gerenciador_Eventos* gerenciador_eventos;

		Personagens::Jogador jogador1;
		Personagens::Jogador* jogador2;
		//Inimigo inimigo1;
		Fantasma fantasma1;
		Plataforma plataforma1;
		Plataforma plataforma2;

		sf::RenderWindow* janela_jogo;
	public:
		Jogo();
		~Jogo();

		void Executar();
};


