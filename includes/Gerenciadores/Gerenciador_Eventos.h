#pragma once
#include "Gerenciador_Grafico.h"
#include <vector>
using namespace std;

namespace Gerenciadores{

    class Gerenciador_Inputs;
}
namespace Gerenciadores{

    class Gerenciador_Eventos {

        private: // Aplicando Singleton:
            static Gerenciador_Eventos* pGE; 
            Gerenciador_Eventos();
            Gerenciador_Grafico* pGG; // para resgatarmos as janelas
            Gerenciador_Inputs* pGI;
            sf::Event evento;
           
        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            bool teclaSolta(sf::Keyboard::Key tecla);
            bool teclaPressionada(sf::Keyboard::Key tecla);
            void gerencia();

    };

}


