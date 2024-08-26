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

}

Gerenciador_Inputs:: ~Gerenciador_Inputs() {

    if(gI)
        delete gI;
    gI = NULL;

    comandosFechamento.clear();
    comandosMovimento.clear();
}


void Gerenciador_Inputs:: gerenciaTeclasPressionadas(){

    std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();

    while(it != comandosMovimento.end()){

        if(*it == pGE->teclaPressionada(*it))
            obs.notificaTeclaPressionadaJog(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(*it == pGE->teclaPressionada(*it))
            obs.notificaTeclaPressionadaJan(*it);
        it++;
    }

}

void Gerenciador_Inputs:: gerenciaTeclasSoltas(){

    std::vector<sf::Keyboard::Key>::iterator it = comandosMovimento.begin();

    while(it != comandosMovimento.end()){

        if(*it == pGE->teclaSolta(*it))
            obs.notificaTeclaSoltaJog(*it);
        it++;
    }


    it = comandosFechamento.begin();
    while(it != comandosFechamento.end()){

        if(*it == pGE->teclaSolta(*it))
            obs.notificaTeclaSoltaJan(*it);
        it++;
    }

}

