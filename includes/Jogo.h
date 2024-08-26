#pragma once
#include <iostream>
#include "Entidades/Obstaculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Eventos.h" 
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Entidades/Personagens/Fantasma.h"
//#include "Gerenciadores/Gerenciador_Estados.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

class Jogo
{
	private:
		Gerenciador_Grafico* gerenciador_grafico;
		Gerenciador_Eventos* gerenciador_eventos;
		Gerenciador_Colisoes* gerenciador_colisoes; 
		//Gerenciador_Estados* gerenciador_estados;
		Personagens::Jogador jogador1;
		Personagens::Jogador* jogador2;
		Inimigo inimigo1;
		Fantasma fantasma1;
		Plataforma plataforma1;
		Plataforma plataforma2;
		Plataforma plataforma3;
		
		sf::RenderWindow* janela_jogo;
	public:
		Jogo();
		~Jogo();

		void Executar();
};


