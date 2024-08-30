#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuSelecao: public Menu
        {
            private:
                bool doisJogadores;
            public:
                MenuSelecao();
                virtual ~MenuSelecao(); 
                void desenhar();
                void executar();
                void setDoisJogadores();
                const bool HaDoisJogadores();
        };
    }
    
}