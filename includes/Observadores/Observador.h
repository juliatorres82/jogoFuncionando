#pragma once
#include "../Gerenciadores/Gerenciador_Inputs.h"

//Aplicando padrão de projeto Observer
namespace Observadores {
    
        class Observador {

            protected:
                Gerenciadores::Gerenciador_Inputs* pGI;

            private:
                bool ativo;

            public:
                Observador(bool ativado = true);
                virtual ~Observador(); 
                
                virtual void notificaTeclaPressionada(const sf::Keyboard::Key) = 0;
                virtual void notificaTeclaSolta(const sf::Keyboard:: Key) = 0;
                void addObservadorVigiando();
                void mudaEstadoAtivo();
                bool getEstadoAtivo();
        };
}