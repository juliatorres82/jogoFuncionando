#include "../../includes/Observadores/ObservadorJog.h"

Observadores::ObservadorJog::ObservadorJog()
{
    pJogando = nullptr;
    pjogador = nullptr;
}

Observadores::ObservadorJog::ObservadorJog(Estados::Jogando *pJog) : Observador()
{
    pJogando = pJog;
    pjogador = nullptr;
    if (pJogando == nullptr) {
        std::cerr << "Erro: menu é nullptr no construtor de ObservadorMenu" << std::endl;
        return;
    }
}

Observadores::ObservadorJog::ObservadorJog(Entidades::Personagens::Jogador *pjog) : Observador()
{

    pjogador = pjog;
    pJogando = nullptr;
    if (pjogador == nullptr) {
        std::cerr << "Erro: menu é nullptr no construtor de ObservadorMenu" << std::endl;
        return;
    }
}

Observadores::ObservadorJog::~ObservadorJog()	
{

        pJogando = nullptr;
        pjogador = nullptr;

}


void Observadores::ObservadorJog::notificaTeclaPressionada(const sf::Keyboard::Key k)
{
    if(pJogando == nullptr)
    {
        if(pjogador!= nullptr)
        {
            if(pjogador->getQJog())
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
    }
    
}

void Observadores::ObservadorJog::notificaTeclaSolta(const sf::Keyboard::Key k)
{
        if(k == sf::Keyboard::Escape && pJogando != nullptr)
        {
            pJogando->pausar();
        }
}
