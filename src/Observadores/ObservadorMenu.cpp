#include "../../includes/Estados/Menus/Menu.h"
namespace Observadores
{
    Observadores::ObservadorMenu::ObservadorMenu(Estados::Menus::Menu* pmenu):
    Observador()
    {
        menu = pmenu;
        if (menu == nullptr) {
            std::cerr << "Erro: menu é nullptr no construtor de ObservadorMenu" << std::endl;
            return;
        }
    }

    Observadores::ObservadorMenu::~ObservadorMenu()
    {
        menu = nullptr;
    }

    void Observadores::ObservadorMenu::notificaTeclaPressionada(const sf::Keyboard::Key tecla)
    {

        if(tecla == sf::Keyboard::Enter)
        {
            menu->selecionar();
        }

        if(tecla == sf::Keyboard::Escape)
        {
           // menu->sairJogo();
           
        }
    }

    void Observadores::ObservadorMenu::notificaTeclaSolta(const sf::Keyboard::Key tecla)
    {
        if (tecla == sf::Keyboard::Up)
        {
            menu->moverCima();

        }
        else if(tecla == sf::Keyboard::Down)
        {
            menu->moverBaixo();
        }
    }

}