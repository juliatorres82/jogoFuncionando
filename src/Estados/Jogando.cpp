#include "../../includes/Estados/Jogando.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
#include "../../includes/Observadores/ObservadorJog.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
    //fase = new Fases::Fase1(false);
    observadorJog = new Observadores::ObservadorJog(this);
}

Estados::Jogando::~Jogando()
{
    if(fase)
    {
        delete fase;
    }
    fase = nullptr;
}

void Estados::Jogando::criaFase(bool coop)
{
    fase = new Fases::Fase1(coop); 
}

void Estados::Jogando::exec()
{   
    if(!observadorJog->getEstadoAtivo())
    {
        observadorJog->mudaEstadoAtivo();
    }

    fase->executar();
}

void Estados::Jogando::atualizar()
{
    fase->atualizar();
}
void Estados::Jogando::pausar()
{
    observadorJog->mudaEstadoAtivo();
    fase->getJogador1()->mudaAtivo();
    if(fase->getJogador2() != nullptr)
        fase->getJogador2()->mudaAtivo();  
    gerenciador_estados->mudaEstado("MenuPausa");
}

Fases::Fase* Estados::Jogando::getFase()
{
    return fase;
}