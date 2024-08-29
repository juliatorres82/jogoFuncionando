#include "../../includes/Estados/Jogando.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
}
Estados::Jogando::~Jogando()
{
    /*if(fase)
    {
        delete fase;
    }
    fase = nullptr;*/
}

void Estados::Jogando::criaFase(bool coop)
{
    //fase = new Fases::Fase1(coop); 
    //fase->constroiFase();
}

void Estados::Jogando::exec()
{
    fase->executar();
}

void Estados::Jogando::atualizar()
{
    fase->atualizar();
}