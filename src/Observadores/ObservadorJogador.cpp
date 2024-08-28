#include "../../includes/Observadores/ObservadorJogador.h"

ObservadorJogador::ObservadorJogador()
{
    pjogador = new Entidades::Personagens::Jogador();
}

ObservadorJogador::~ObservadorJogador()
{
    if(pjogador)
    {
        delete pjogador;
    }
    pjogador = nullptr;
}

void ObservadorJogador::notificaTeclaPressionada(const sf::Keyboard::Key k)
{
    if(pjogador->getQJog() == 0)
    {
     
        switch (k)
        {
            case (sf::Keyboard::Up):
                pjogador->Pular();
                break;
            case (sf::Keyboard::Left):
                pjogador->movEsq();
                break;
            case (sf::Keyboard::Right):
                pjogador->movDir();
                break;
            default:
                break;
         }
    }
    else
    {
        switch (k)
        {
            case (sf::Keyboard::W):
                pjogador->Pular();
                break;
            case (sf::Keyboard::A):
                pjogador->movEsq();
                break;
            case (sf::Keyboard::D):
                pjogador->movDir();
                break;
            default:
                break;
        }
    }
}

void ObservadorJogador::notificaTeclaSolta(const sf::Keyboard::Key k)
{
    
}