#include "ObservadorMenu.h"

ObservadorMenu::ObservadorMenu(Estados::Menu* menu)
{
    this->menu = menu;
}

ObservadorMenu::~ObservadorMenu()
{
    this->menu = nullptr;
}

void ObservadorMenu::notificaTeclaPressionada(const sf::Keyboard::Key tecla)
{
    if(tecla == sf::Keyboard::Up)
    {
        menu->moverCima();
    }
    else if(tecla == sf::Keyboard::Down)
    {
        menu->moverBaixo();
    }
    else if(tecla == sf::Keyboard::Enter)
    {
        menu->selecionar();
    }
}

void ObservadorMenu::notificaTeclaSolta(const sf::Keyboard::Key)
{
    
}
