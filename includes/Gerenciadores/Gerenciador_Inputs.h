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
            static Gerenciador_Inputs* gI;
            Gerenciador_Inputs();
            std::vector<sf::Keyboard::Key> comandosMovimento;
            std::vector<sf::Keyboard::Key> comandosFechamento;
            Gerenciador_Grafico* pGG;
            Gerenciador_Eventos* pGE;
            std::list<Observador*> observadoresVigiando;


        public:
            ~Gerenciador_Inputs();
            Gerenciador_Inputs* getInstancia();
            void addObservadoresVigiando(Observador* obs);
            void tiraObservadoresVigiando(Observador* obs);
            void gerenciaTeclasPressionadas();
            void gerenciaTeclasSoltas();
    };



}