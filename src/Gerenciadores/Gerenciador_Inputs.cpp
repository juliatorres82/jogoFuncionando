#include "../../includes/Observadores/Observador.h"
using namespace Gerenciadores;

Gerenciador_Inputs* Gerenciador_Inputs:: gI = nullptr;
Gerenciador_Grafico* Gerenciador_Inputs:: pGG = Gerenciador_Grafico::getInstancia();
Gerenciador_Eventos* Gerenciador_Inputs:: pGE = Gerenciador_Eventos::getGerenciadorEventos();

Gerenciador_Inputs:: Gerenciador_Inputs(){

    gI = getInstancia();

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
    gI = nullptr;

    comandosFechamento.clear();
    comandosMovimento.clear();
    observadoresVigiando.clear();
}

Gerenciador_Inputs* Gerenciador_Inputs::getInstancia(){

    if(gI = nullptr)
    {
        gI = new Gerenciador_Inputs();
    }
    return gI;
}


void Gerenciador_Inputs::addObservadoresVigiando(Observadores::Observador* obs){
    
    if(obs)
    {
       observadoresVigiando.push_back(obs);
    }
}


void Gerenciador_Inputs::tiraObservadoresVigiando(Observadores::Observador* obs){
    
    if(obs){
       observadoresVigiando.remove(obs);
    }
}


void Gerenciador_Inputs:: gerenciaTeclasPressionadas(){
/*
    std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();
    std::list<Observadores::Observador*>::iterator itObs = observadoresVigiando.begin();

    while(it != comandosMovimento.end()){

        if(pGE->teclaPressionada(*it)) //verifica qual a tecla pressionada
            for(itObs; itObs != observadoresVigiando.end(); itObs++) //conta para todos os observadores
                (*itObs)->notificaTeclaPressionada(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(pGE->teclaPressionada(*it))
            for(itObs; itObs != observadoresVigiando.end(); itObs++)
                (*itObs)->notificaTeclaPressionada(*it);
        it++;
    }
*/
}


void Gerenciador_Inputs:: gerenciaTeclasSoltas(){

    /*std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();
    std::list<Observadores::Observador*>::iterator itObs = observadoresVigiando.begin();

    while(it != comandosMovimento.end()){

        if(pGE->teclaSolta(*it)) 
            for(itObs; itObs!=observadoresVigiando.end(); itObs++) 
                (*itObs)->notificaTeclaSolta(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(pGE->teclaSolta(*it))
            for(itObs; itObs!=observadoresVigiando.end(); itObs++) 
                (*itObs)->notificaTeclaSolta(*it);
        it++;
    }
*/
}
