#pragma once
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"

using namespace Gerenciadores;

class Gerenciadores::Gerenciador_Colisoes;

enum idEntes 
{
	jogaDor,
	iniMigo,
	obsTaculo,
	plataForma,
	botao,
	menu
};

class Ente
{
	protected:
		idEntes id;
		static Gerenciadores::Gerenciador_Grafico* pGG;
		static Gerenciadores::Gerenciador_Colisoes* pGC;

	public:
		Ente(idEntes ID = jogaDor);
		~Ente();
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		idEntes getId();
};



		
