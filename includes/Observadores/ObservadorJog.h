#include "Observador.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Estados/Jogando.h"

namespace Observadores
{
    class ObservadorJog : public Observador
    {

        private:
            Estados::Jogando* pJogando;
            Entidades::Personagens::Jogador* pjogador;
        public:
            ObservadorJog();
            ObservadorJog(Estados::Jogando* pJog);
            ObservadorJog(Entidades::Personagens::Jogador *pjog);
            ~ObservadorJog();
            void notificaTeclaPressionada(const sf::Keyboard::Key);
            void notificaTeclaSolta(const sf::Keyboard::Key);
    };
}