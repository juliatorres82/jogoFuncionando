#include "../includes/Ente.h"


Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::Ente(idEntes ID):
	id(ID)
{

}

Ente::~Ente()
{
}

idEntes Ente::getId()
{
	return id;
}

