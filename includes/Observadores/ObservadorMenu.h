#include "Observador.h"
#include "../Estados/Menus/Menu.h"

namespace Observadores
{
    class ObservadorMenu : public Observador
    {
        private:
            Estados::Menus::Menu* menu;
        public:
            ObservadorMenu(Estados::Menus::Menu* pmenu = nullptr);
            ~ObservadorMenu();
            void notificaTeclaPressionada(const sf::Keyboard::Key);
            void notificaTeclaSolta(const sf::Keyboard::Key);
    };

}