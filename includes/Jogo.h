#pragma once
#include <iostream>
#include "Entidades/Obstaculos/Plataforma.h"
#include "Gerenciadores/Gerenciador_Eventos.h" 
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Entidades/Personagens/Fantasma.h"
#include "Estados/Menu.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

class Jogo
{
	private:
		Gerenciador_Grafico* gerenciador_grafico;
		Gerenciador_Eventos* gerenciador_eventos;
		Gerenciador_Colisoes* gerenciador_colisoes; 
		Gerenciadores::Gerenciador_Estados* gerenciador_estados;
		
		sf::RenderWindow* janela_jogo;
	public:
		Jogo();
		~Jogo();

		void Executar();
};


