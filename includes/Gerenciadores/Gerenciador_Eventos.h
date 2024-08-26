#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Jogador.h"
using namespace Entidades::Personagens;

namespace Gerenciadores{

    class Gerenciador_Eventos {


        private: // Aplicando Singleton:

            static Gerenciador_Eventos* pGE; 
            Gerenciador_Eventos();
            Gerenciador_Grafico* pGG; // para resgatarmos as janelas
            sf::Event evento;
            Entidades::Personagens::Jogador* jog1 = nullptr; // para resgatarmos os jogadores

        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            bool teclaPressionada(sf::Keyboard::Key tecla);
            bool teclaSolta(sf::Keyboard::Key tecla);
            const bool haEventos();
            void apertaTecla();
            bool isDoisJogadores() const;
    };

}