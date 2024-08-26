#include "../../includes/Gerenciadores/Gerenciador_Eventos.h"

using namespace Gerenciadores;

Gerenciador_Eventos* Gerenciador_Eventos:: pGE (nullptr);


Gerenciador_Eventos::Gerenciador_Eventos() : pGG(nullptr), jog1(nullptr){
    //perguntar a um monitor se faz sentido inicializar pGG com NULL ---------------------------

    vetorTeclasJog.push_back(sf::Keyboard::Key::A);
    vetorTeclasJog.push_back(sf::Keyboard::Key::W);
    vetorTeclasJog.push_back(sf::Keyboard::Key::D);
    vetorTeclasJog.push_back(sf::Keyboard::Key::S);
    vetorTeclasJog.push_back(sf::Keyboard::Key::Space);
    vetorTeclasJog.push_back(sf::Keyboard::Key::Up);
    vetorTeclasJog.push_back(sf::Keyboard::Key::Right);
    vetorTeclasJog.push_back(sf::Keyboard::Key::Left);
    vetorTeclasJog.push_back(sf::Keyboard::Key::Down);

    vetorTeclasGG.push_back(sf::Keyboard::Key::Escape);
    vetorTeclasGG.push_back(sf::Keyboard::Key::Enter);

}

Gerenciador_Eventos::~Gerenciador_Eventos(){

    if(pGE)
        delete pGE;
    pGE = NULL;

       if (jog1->getJogador2())
       delete jog1->getJogador2();
}

void Gerenciador_Eventos:: setJogador(Jogador* j1, Jogador* j2){

    jog1 = j1;
    if(j2)
        jog1->setJogador2(j2);

}

void Gerenciador_Eventos:: setGerenciadorGrafico(Gerenciador_Grafico* gg){
    pGG = gg;
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

    std::vector<sf::Keyboard::Key>::iterator it = vetorTeclasGG.begin();

    while(haEventos()){
        if(sf::Keyboard::isKeyPressed(*it)){
            pGG->getJanela()->close();
        }
    }
}


void Gerenciador_Eventos::gerencia(){

    if (pGG){
        while(pGG->getJanela()->pollEvent(evento)){
            apertaTecla();
        }
    }
}