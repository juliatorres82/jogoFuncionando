#include "../../includes/Gerenciadores/Gerenciador_Eventos.h"

using namespace Gerenciadores;

Gerenciador_Eventos* Gerenciador_Eventos:: pGE (nullptr);


Gerenciador_Eventos::Gerenciador_Eventos() : pGG(nullptr){
    pGG = Gerenciador_Grafico::getInstancia();
}


Gerenciador_Eventos::~Gerenciador_Eventos(){

    if(pGE)
        delete pGE;
    pGE = NULL;

}

Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){

    if(pGE == NULL){ // se ainda não instanciado 
        pGE = new Gerenciador_Eventos();
    }
    return pGE;

}

bool Gerenciadores::Gerenciador_Eventos::teclaPressionada(sf::Keyboard::Key tecla)
{
	return sf::Keyboard::isKeyPressed(tecla);
}


bool Gerenciadores::Gerenciador_Eventos::teclaSolta(sf::Keyboard::Key tecla)
{
    if(evento.type == evento.KeyReleased){
	    if(evento.key.code == tecla)
            return true;
    }
    return false;
}


void Gerenciador_Eventos::gerencia(){

    /*while(pGG->janelaAberta()){
        if(pGG->getJanela()->pollEvent(evento)){
            
            if(evento.type == sf::Event::KeyPressed)
                pGI->gerenciaTeclasPressionadas();

            if (evento.type == sf::Event::KeyReleased)
               pGI->gerenciaTeclasSoltas();
            
            if(evento.type == sf::Event::Closed) 
                pGG->fecharJanela();
        }

    }
*/
}
