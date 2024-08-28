#include "../../includes/Estados/Jogando.h"

Jogando::Jogando()
{
    //fase = new Fases::Fase1();
}

Jogando::~Jogando()
{
    /*if(fase)
    {
        delete fase;
    }
    fase = nullptr;*/
}

void Jogando::exec()
{
    fase->executar();
}

void Jogando::atualizar()
{
    fase->atualizar();
}