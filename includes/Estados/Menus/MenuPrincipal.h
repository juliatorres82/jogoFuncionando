#pragma once
#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal: public Menu
        {
        private:
            bool doisJogadores;
        public:
            MenuPrincipal();
            virtual ~MenuPrincipal(); 
            void exec(); 
            void desenhar();
            void executar();
            void setDoisJogadores();
            const bool HaDoisJogadores();
        };
    }
    
}
