#include "../includes/Ente.h"


Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::Ente(idEntes ID):
	id(ID)
{

}

Ente::~Ente()
{
}

void Ente::setGG(Gerenciador_Grafico* g)
{
	pGG = g;
}

idEntes Ente::getId()
{
	return id;
}

