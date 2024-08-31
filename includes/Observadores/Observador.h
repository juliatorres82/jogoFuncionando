#pragma once
#include "../Gerenciadores/Gerenciador_Inputs.h"

namespace Observadores {
    
        class Observador {

            protected:
                static Gerenciadores::Gerenciador_Inputs* pGI;

            private:
                bool ativo;

            public:
                Observador(bool ativado = false);
                virtual ~Observador(); 
                
                virtual void notificaTeclaPressionada(const sf::Keyboard::Key) = 0;
                virtual void notificaTeclaSolta(const sf::Keyboard:: Key) = 0;
              
                void mudaEstadoAtivo();
                bool getEstadoAtivo();
        };
}