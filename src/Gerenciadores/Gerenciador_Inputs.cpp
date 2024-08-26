#include "../../includes/Gerenciadores/Gerenciador_Inputs.h"

Gerenciador_Inputs* Gerenciador_Inputs:: gI = NULL;

Gerenciador_Inputs:: Gerenciador_Inputs() : pGG(pGG->getInstancia()), pGE(pGE->getGerenciadorEventos()){

    comandosMovimento.push_back(sf::Keyboard::A);
    comandosMovimento.push_back(sf::Keyboard::D);
    comandosMovimento.push_back(sf::Keyboard::Space);
    comandosMovimento.push_back(sf::Keyboard::Up);
    comandosMovimento.push_back(sf::Keyboard::Left);
    comandosMovimento.push_back(sf::Keyboard::Right);


    comandosFechamento.push_back(sf::Keyboard::Escape);
    comandosFechamento.push_back(sf::Keyboard::BackSpace);

    observadoresVigiando.clear();

}

Gerenciador_Inputs:: ~Gerenciador_Inputs() {

    if(gI)
        delete gI;
    gI = NULL;

    comandosFechamento.clear();
    comandosMovimento.clear();
    observadoresVigiando.clear();
}

Gerenciador_Inputs* Gerenciador_Inputs:: getInstancia(){

    if(gI = NULL){
        gI = new Gerenciador_Inputs();
    }
    return gI;
}


void Gerenciador_Inputs::addObservadoresVigiando(Observador* obs){
    
    if(obs){
       observadoresVigiando.push_back(obs);
    }
}


void Gerenciador_Inputs::tiraObservadoresVigiando(Observador* obs){
    
    if(obs){
       observadoresVigiando.remove(obs);
    }
}


void Gerenciador_Inputs:: gerenciaTeclasPressionadas(){

    std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();
    std::list<Observador*>::iterator itObs = observadoresVigiando.begin();


    while(it != comandosMovimento.end()){

        if(*it == pGE->teclaPressionada(*it)) //verifica qual a tecla pressionada
            for(itObs; itObs!=observadoresVigiando.end(); itObs++) //conta para todos os observadores
                (*itObs)->notificaTeclaPressionadaJog(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(*it == pGE->teclaPressionada(*it))
            for(itObs; itObs!=observadoresVigiando.end(); itObs++)
                (*itObs)->notificaTeclaPressionadaJan(*it);
        it++;
    }

}


void Gerenciador_Inputs:: gerenciaTeclasSoltas(){

    std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();
    std::list<Observador*>::iterator itObs = observadoresVigiando.begin();

    while(it != comandosMovimento.end()){

        if(*it == pGE->teclaSolta(*it)) 
            for(itObs; itObs!=observadoresVigiando.end(); itObs++) 
                (*itObs)->notificaTeclaSoltaJog(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(*it == pGE->teclaSolta(*it))
            for(itObs; itObs!=observadoresVigiando.end(); itObs++) 
                (*itObs)->notificaTeclaSoltaJan(*it);
        it++;
    }

}

