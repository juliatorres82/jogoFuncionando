#include "../../includes/Estados/Jogando.h"

Jogando::Jogando()
{
    fase = nullptr;
}

Jogando::~Jogando()
{
    if(fase)
    {
        delete fase;
    }
    fase = nullptr;
}

void Jogando::exec(bool coop)
{
    fase->executar(coop);
}

void Jogando::atualizar()
{
    fase->atualizar();
}

void Jogando::criaFase1()
{
    fase = new Fase1();
}

void Jogando::criaFase2()
{
    fase = 
}