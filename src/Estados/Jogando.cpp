#include "../../includes/Estados/Jogando.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
#include "../../includes/Observadores/ObservadorJogador.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
    //fase = new Fases::Fase1(false);
    observadorJogador = new Observadores::ObservadorJogador(this);
}

Estados::Jogando::~Jogando()
{
    /*if(fase)
    {
        delete fase;
    }
    fase = nullptr;
    */
}

void Estados::Jogando::criaFase(bool coop)
{
    fase = new Fases::Fase2(coop); 
}

void Estados::Jogando::exec()
{   
    if(!observadorJogador->getEstadoAtivo())
    {
        observadorJogador->mudaEstadoAtivo();
    }

    fase->executar();
}

void Estados::Jogando::atualizar()
{
    fase->executar();
}
void Estados::Jogando::pausar()
{
    observadorJogador->mudaEstadoAtivo();
    gerenciador_estados->mudaEstado("MenuPausa");
}

Fases::Fase* Estados::Jogando::getFase()
{
    return fase;
}