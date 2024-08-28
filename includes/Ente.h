#pragma once
#include "Gerenciadores/Gerenciador_Grafico.h"
using namespace Gerenciadores;

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

	public:
		Ente(idEntes ID = jogaDor);
		~Ente();
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		static void setGG(Gerenciadores::Gerenciador_Grafico* gG);
		idEntes getId();
};



		
