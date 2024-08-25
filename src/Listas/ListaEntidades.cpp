#include "../../includes/Listas/ListaEntidades.h"

using namespace Listas;

ListaEntidades::ListaEntidades()
{
	
}

ListaEntidades::~ListaEntidades()
{
	listaEnt.limpaLista();
}

void ListaEntidades::incluir(Entidade* pEnt)
{
	listaEnt.incluir(pEnt);
}

void ListaEntidades::desenhaLista()
{
	Lista<Entidade>::Iterador it = listaEnt.getInicio();
	while (!it.isNulo())
	{
		(*it)->desenhar();
		++it;
	}
}

void ListaEntidades::executaLista()
{
	Lista<Entidade>::Iterador it = listaEnt.getInicio();
	while (!it.isNulo())
	{
		(*it)->executar();
		++it;
	}
}

void ListaEntidades:: limpar(){

	listaEnt.limpaLista();
}

Lista<Entidade>::Iterador ListaEntidades:: getInicio(){

	return listaEnt.getInicio();
}