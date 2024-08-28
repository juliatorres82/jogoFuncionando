#pragma once
#include <vector>
#include <list>
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "../Observadores/Observador.h"

using namespace std;

namespace Gerenciadores {

    class Gerenciador_Inputs {

        private:
            std::vector<sf::Keyboard::Key> comandosMovimento;
            std::vector<sf::Keyboard::Key> comandosFechamento;
            static Gerenciador_Grafico* pGG;
            static Gerenciador_Eventos* pGE;
            std::list<Observador*> observadoresVigiando;

            static Gerenciador_Inputs* gI;
            Gerenciador_Inputs();

        public:
            ~Gerenciador_Inputs();
            Gerenciador_Inputs* getInstancia();
            void addObservadoresVigiando(Observador* obs);
            void tiraObservadoresVigiando(Observador* obs);
            void gerenciaTeclasPressionadas();
            void gerenciaTeclasSoltas();
    };



}