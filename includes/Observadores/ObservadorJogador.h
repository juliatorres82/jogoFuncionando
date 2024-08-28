#include "Observador.h"
#include "../Entidades/Personagens/Jogador.h"
class ObservadorJogador : public Observador
{

    private:
        Entidades::Personagens::Jogador* pjogador;
    public:
        ObservadorJogador();
        ~ObservadorJogador();
        void notificaTeclaPressionada(const sf::Keyboard::Key);
        void notificaTeclaSolta(const sf::Keyboard::Key);
};