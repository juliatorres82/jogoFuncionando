#pragma once
#include "Gerenciadores/Gerenciador_Grafico.h"

namespace Gerenciadores {
	class Gerenciador_Colisoes;
}

enum idEntes 
{
	jogaDor,
	iniMigo,
	obsTaculo,
	plataForma,
	botao,
	menu, 
	fase
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



		
