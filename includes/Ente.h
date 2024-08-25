#pragma once
#include "Gerenciadores/Gerenciador_Grafico.h"
using namespace Gerenciadores;

enum idEntes 
{
	jogaDor,
	iniMigo,
	obsTaculo,
	plataForma
};

class Ente
{
	protected:
		idEntes id;
		static Gerenciador_Grafico* pGG;

	public:
		Ente();
		~Ente();
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		static void setGG(Gerenciador_Grafico* gG);
		int getId();
};



		
