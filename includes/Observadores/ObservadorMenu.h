#include "Observador.h"
#include "../Estados/Menu.h"

namespace Observadores
{
    class ObservadorMenu : public Observador
    {
        private:
            Estados::Menu* menu;
        public:
            ObservadorMenu(Estados::Menu* pmenu);
            ~ObservadorMenu();
            void notificaTeclaPressionada(const sf::Keyboard::Key);
            void notificaTeclaSolta(const sf::Keyboard::Key);
    };

}