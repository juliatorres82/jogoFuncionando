#pragma once
#include <vector>
#include <list>
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"

namespace Observadores {
    class Observador;
}

using namespace std;

namespace Gerenciadores {

    class Gerenciador_Inputs {

        private:
            std::vector<sf::Keyboard::Key> comandosMovimento;
            std::vector<sf::Keyboard::Key> comandosFechamento;
            static Gerenciador_Grafico* pGG;
            static Gerenciador_Eventos* pGE;
            std::list<Observadores::Observador*> observadoresVigiando;

            static Gerenciador_Inputs* gI;
            Gerenciador_Inputs();

        public:
            ~Gerenciador_Inputs();
            static Gerenciador_Inputs* getInstancia();
            void addObservadoresVigiando(Observadores::Observador* obs);
            void tiraObservadoresVigiando(Observadores::Observador* obs);
            void gerenciaTeclasPressionadas();
            void gerenciaTeclasSoltas();
    };



}