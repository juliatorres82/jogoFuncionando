#include "../../includes/Gerenciadores/Gerenciador_Eventos.h"
using namespace Gerenciadores;

Gerenciador_Eventos* Gerenciador_Eventos:: pGE (NULL);


Gerenciador_Eventos::Gerenciador_Eventos() : pGG(NULL), jog1(NULL){
    //perguntar a um monitor se faz sentido inicializar pGG com NULL ---------------------------
}

Gerenciador_Eventos::~Gerenciador_Eventos(){

    if(pGE)
        delete pGE;
    pGE = NULL;

}

const bool Gerenciador_Eventos:: isDoisJogadores(){ // depois o menu vai interferir nessa função aqui

    if(jog1!=NULL){
        if(jog1->getJogador2()!=NULL)
            return true;
    }
    return false;
}


Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){

    if(pGE == NULL){ // se ainda não instanciado 
        pGE = new Gerenciador_Eventos();
    }
    return pGE;

}

const bool Gerenciador_Eventos:: haEventos(){

    if(pGG->janelaAberta()){
        if(pGG->getJanela()->pollEvent(evento))
            return true;
        }
    return false;

}

void Gerenciador_Eventos:: apertaTecla(){

    while(haEventos()){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		    jog1->movDir();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            jog1->movEsq();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            jog1->Pular();
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            pGG->fecharJanela();
        

        if(isDoisJogadores()){

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		        jog1->getJogador2()->movDir();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                jog1->getJogador2()->movEsq();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                jog1->getJogador2()->Pular();
        }
    }

}
