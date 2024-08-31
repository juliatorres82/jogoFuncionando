#include "../../includes/Estados/Jogando.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
#include "../../includes/Observadores/ObservadorJogador.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
    observadorJogador = new Observadores::ObservadorJogador(this);
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
    fase = new Fases::Fase(coop);
    fase->constroiFase();
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
    fase->atualizar();
}
void Estados::Jogando::pausar()
{
    observadorJogador->mudaEstadoAtivo();
    gerenciador_estados->mudaEstado("MenuPausa");
}