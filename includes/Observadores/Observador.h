#pragma once
#include "../Gerenciadores/Gerenciador_Inputs.h"

//Aplicando padrão de projeto Observer
class Observador {

    private:
        Gerenciador_Inputs* pGI;

    public:
        Observador();
        ~Observador(); 
        
        void notificaTeclaPressionadaJog(sf::Keyboard::Key);
        void notificaTeclaSoltaJog (sf::Keyboard:: Key);
        void notificaTeclaPressionadaJan(sf::Keyboard::Key);
        void notificaTeclaSoltaJan(sf::Keyboard::Key);

};