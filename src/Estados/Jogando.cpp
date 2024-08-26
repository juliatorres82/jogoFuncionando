#include "../../includes/Estados/Jogando.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"

Jogando::Jogando()
{
    fase = new Fases::Fase();
}

Jogando::~Jogando()
{
    if(fase)
    {
        delete fase;
    }
    fase = nullptr;
}

void Jogando::exec()
{
    fase->executar();
}

void Jogando::atualizar()
{
    fase->executar();
}

void Jogando::iniciar()
{
    fase->iniciar();
}