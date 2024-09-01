#include "Observador.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Estados/Jogando.h"
namespace Observadores
{
    class ObservadorJogador : public Observador
    {

        private:
            Estados::Jogando* pJogando;
            Entidades::Personagens::Jogador* pjogador1;
            Entidades::Personagens::Jogador* pjogador2;
        public:
            ObservadorJogador(Estados::Jogando* pJog);
            ~ObservadorJogador();
            void setJogadores(Entidades::Personagens::Jogador* pj, Entidades::Personagens::Jogador* pj2);
            void notificaTeclaPressionada(const sf::Keyboard::Key);
            void notificaTeclaSolta(const sf::Keyboard::Key);
    };
}