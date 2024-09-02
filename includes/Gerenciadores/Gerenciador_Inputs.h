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
            static Gerenciador_Grafico* pGG;
            static Gerenciador_Eventos* pGE;
            std::list<Observadores::Observador*> observadoresVigiando;

            static Gerenciador_Inputs* gI;
            Gerenciador_Inputs();
            ~Gerenciador_Inputs();
        public:
            static void deletaInstancia();
            static Gerenciador_Inputs* getInstancia();

            void addObservadoresVigiando(Observadores::Observador* obs);
            void tiraObservadoresVigiando(Observadores::Observador* obs);
            void gerenciaTeclasPressionadas(sf::Keyboard::Key tecla);
            void gerenciaTeclasSoltas(sf::Keyboard::Key tecla);
    };


}