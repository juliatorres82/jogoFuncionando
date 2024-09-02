#include "../includes/Ente.h"
#include "../includes/Gerenciadores/Gerenciador_Colisoes.h"


Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;
Gerenciadores::Gerenciador_Colisoes* Ente::pGC = nullptr;

Ente::Ente(idEntes ID): id(ID) {
	pGG = pGG->getInstancia();
	pGC = pGC->getInstancia();
}

Ente::~Ente()
{
	pGG = nullptr;
	pGC = nullptr;
}

idEntes Ente::getId()
{
	return id;
}

