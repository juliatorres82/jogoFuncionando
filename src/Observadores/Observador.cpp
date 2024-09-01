#include "../../includes/Observadores/Observador.h"

namespace Observadores{

    Gerenciadores::Gerenciador_Inputs* Observador::pGI = Gerenciadores::Gerenciador_Inputs::getInstancia();

    Observadores::Observador::Observador(bool ativado):
    ativo(ativado) 
    {  
        if(pGI != nullptr && this != nullptr)
        {   
            pGI->addObservadoresVigiando(this); //cada gerenciador de Inputs inscreve o observador
        }

        if(pGI == nullptr)
        {
            std::cerr << "Erro: pGI eh nullptr no construtor de Observador" << std::endl;
        }

        if(this == nullptr)
        {
            std::cerr << "Erro: this eh nullptr no construtor de Observador" << std::endl;
        }
    }

    Observadores::Observador:: ~Observador() {
        pGI->tiraObservadoresVigiando(this);
        pGI = nullptr;
    }

    void Observadores::Observador::mudaEstadoAtivo()
    {
        ativo = !ativo; 
    }

    bool Observadores::Observador::getEstadoAtivo()
    {
        return ativo;
    }

}
