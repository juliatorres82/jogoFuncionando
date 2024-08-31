#include "../../includes/Observadores/ObservadorJogador.h"

Observadores::ObservadorJogador::ObservadorJogador(Estados::Jogando* pJog): Observador()
{
    pJogando = pJog;
    if (pJogando == nullptr) {
        std::cerr << "Erro: menu é nullptr no construtor de ObservadorMenu" << std::endl;
        return;
    }
    pjogador1 = nullptr;
    pjogador2 = nullptr;
}

Observadores::ObservadorJogador::~ObservadorJogador()
{
    if(pJogando)
    {
        delete pJogando;
    }
    pJogando = nullptr;

    if(pjogador1)
    {
        delete pjogador1;
    }
    pjogador1 = nullptr;
    
    if(pjogador2)
    {
        delete pjogador2;
    }
    pjogador2 = nullptr;
}


void Observadores::ObservadorJogador::setJogadores(Entidades::Personagens::Jogador* pj, Entidades::Personagens::Jogador* pj2)
{
    pjogador1 = pj;
    pjogador2 = pj2;
}


void Observadores::ObservadorJogador::notificaTeclaPressionada(const sf::Keyboard::Key k)
{
    /*
        switch (k)
        {
            case (sf::Keyboard::Up):
                pjogador2->Pular();
                break;
            case (sf::Keyboard::Left):
                pjogador2->movEsq();
                break;
            case (sf::Keyboard::Right):
                pjogador2->movDir();
                break;
            default:
                break;
         }
   
        switch (k)
        {
            case (sf::Keyboard::W):
                pjogador1->Pular();
                break;
            case (sf::Keyboard::A):
                pjogador1->movEsq();
                break;
            case (sf::Keyboard::D):
                pjogador1->movDir();
                break;
            default:
                break;
        }
    */
    
}

void Observadores::ObservadorJogador::notificaTeclaSolta(const sf::Keyboard::Key k)
{
        if(k == sf::Keyboard::Escape)
        {
            pJogando->pausar();
        }
}
