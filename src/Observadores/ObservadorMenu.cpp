#include "../../includes/Observadores/ObservadorMenu.h"

Observadores::ObservadorMenu::ObservadorMenu(Estados::Menu* pmenu):
Observador(true)
{
    this->menu = menu;
}

Observadores::ObservadorMenu::~ObservadorMenu()
{
    this->menu = nullptr;
}

void Observadores::ObservadorMenu::notificaTeclaPressionada(const sf::Keyboard::Key tecla)
{

    if(tecla == sf::Keyboard::Enter)
    {
        menu->selecionar();
    }
}

void Observadores::ObservadorMenu::notificaTeclaSolta(const sf::Keyboard::Key tecla)
{
    if ((tecla) == sf::Keyboard::Up)
    {
        menu->moverCima();
    }
    else if(tecla == sf::Keyboard::Down)
    {
        menu->moverBaixo();
    }
}
