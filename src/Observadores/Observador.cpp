#include "../../includes/Observadores/Observador.h"

Observadores::Observador::Observador(bool ativado):
ativo(ativado) 
{
    this->pGI = pGI->getInstancia(); //cada instância vigia o gerenciador de Inputs
    pGI->addObservadoresVigiando(this); //cada gerenciador de Inputs inscreve o observador
}

Observadores::Observador:: ~Observador() {
    pGI->tiraObservadoresVigiando(this);
}

void Observadores::Observador::mudaEstadoAtivo()
{
    ativo = !ativo; 
}

bool Observadores::Observador::getEstadoAtivo()
{
    return ativo;
}

void Observadores::Observador::addObservadorVigiando()
{
    pGI->addObservadoresVigiando(this);
}

