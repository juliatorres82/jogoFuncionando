#include "../../includes/Estados/Jogando.h"

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

void Jogando::criaFase()
{
    fase->constroiFase();
}
void Jogando::exec()
{
    fase->executar();
}

void Jogando::atualizar()
{
    fase->atualizar();
}