#pragma once
#include <iostream>
#include "Entidades/Obstaculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Eventos.h" 
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Entidades/Personagens/Fantasma.h"
#include "Estados/Menu.h"
#include "Fase/Fase.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Fases;

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* gerenciador_grafico;
		Gerenciadores::Gerenciador_Eventos* gerenciador_eventos;
		Gerenciadores::Gerenciador_Colisoes* gerenciador_colisoes; 
		//Gerenciador_Estados* gerenciador_estados;
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


