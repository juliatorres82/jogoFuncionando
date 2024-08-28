#include "Observador.h"
#include "../Estados/Menu.h"

class ObservadorMenu : public Observador
{
    private:
        Estados::Menu* menu;
    public:
        ObservadorMenu(Estados::Menu* menu);
        ~ObservadorMenu();
        void notificaTeclaPressionada(const sf::Keyboard::Key);
        void notificaTeclaSolta(const sf::Keyboard::Key);
};