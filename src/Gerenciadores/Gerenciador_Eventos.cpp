#include "../../includes/Gerenciadores/Gerenciador_Eventos.h"

using namespace Gerenciadores;

Gerenciador_Eventos* Gerenciador_Eventos:: pGE (nullptr);


Gerenciador_Eventos::Gerenciador_Eventos() : pGG(nullptr), jog1(nullptr){
    //perguntar a um monitor se faz sentido inicializar pGG com NULL ---------------------------
}

Gerenciador_Eventos::~Gerenciador_Eventos(){

    if(pGE)
        delete pGE;
    pGE = NULL;

       if (jog1->getJogador2())
       delete jog1->getJogador2();
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

const bool Gerenciador_Eventos:: haEventos(){

    if(pGG->janelaAberta()){
        if(pGG->getJanela()->pollEvent(evento))
            return true;
        }
    return false;

}

void Gerenciador_Eventos:: apertaTecla(){

    while (haEventos()) 
 {

        if (evento.type == sf::Event::Closed)
            pGG->fecharJanela();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            pGG->fecharJanela();

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !(jog1->doisJogadores()))
        {
            jog1->setJogador2(new Entidades::Personagens::Jogador(jog1));
        }

 }
}

bool Gerenciadores::Gerenciador_Eventos::isDoisJogadores() const
{
    return jog1->doisJogadores();
}