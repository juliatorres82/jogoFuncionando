#include "../includes/Ente.h"


Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::Ente(): id(jogaDor) {
	pGG = pGG->getInstancia();
	pGC = pGC->getInstancia();
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

