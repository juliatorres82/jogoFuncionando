#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Jogador.h"
#include <vector>
using namespace Entidades::Personagens;
using namespace std;

namespace Gerenciadores{

    class Gerenciador_Eventos {


        private: // Aplicando Singleton:

            static Gerenciador_Eventos* pGE; 
            Gerenciador_Eventos();
            Gerenciadores::Gerenciador_Grafico* pGG; // para resgatarmos as janelas
            sf::Event evento;
           

        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            bool teclaSolta(sf::Keyboard::Key tecla);
            bool teclaPressionada(sf::Keyboard::Key tecla);
            void gerencia();

    };

}
