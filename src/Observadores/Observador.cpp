#include "../../includes/Observadores/Observador.h"

Observador:: Observador() {
    
    this->pGI = pGI->getInstancia(); //cada instância vigia o gerenciador de Inputs
    pGI->addObservadoresVigiando(this); //cada gerenciador de Inputs inscreve o observador
}

Observador:: ~Observador() {
    pGI->tiraObservadoresVigiando(this);
}

void Observador::notificaTeclaPressionadaJog(sf::Keyboard::Key tecla){
        
}