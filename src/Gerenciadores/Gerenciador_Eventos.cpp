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
	return !sf::Keyboard::isKeyPressed(tecla);
}


void Gerenciador_Eventos::gerencia(){

    while(pGG->janelaAberta()){
        if(pGG->getJanela()->pollEvent(evento)){
            
            if(evento.type == sf::Event::KeyPressed)
                //chama observador

            if (evento.type == sf::Event::KeyReleased)
               //chama observador
            
            if(evento.type == sf::Event::Closed) //requisita à janela fechar
                pGG->fecharJanela();
        }

    }

}