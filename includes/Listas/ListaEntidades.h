#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"
using namespace Entidades;

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> listaEnt;

	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidade* pEnt);
		void desenhaLista();
		void executaLista();
		void limpar();
		Lista<Entidade>::Iterador getInicio();
		Entidade* getPrimeiro();
	};
}
