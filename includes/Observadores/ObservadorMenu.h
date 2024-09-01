#include "Observador.h"

namespace Estados
{
    namespace Menus
    {
        class Menu;
    }
}

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