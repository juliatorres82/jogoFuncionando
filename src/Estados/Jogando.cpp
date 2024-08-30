#include "../../includes/Estados/Jogando.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
    printf("constr. jogando funcionando\n"); //tetse
    criaFase(false); //P TESTE
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
    Fases::Fase1* fase = new Fases::Fase1(coop); 
    fase->constroiFase();
}

void Estados::Jogando::exec()
{
    printf("jogando->exec() funcionando; vai chamar executar() de fase\n");
    fase->executar();
}

void Estados::Jogando::atualizar()
{
    fase->atualizar();
}