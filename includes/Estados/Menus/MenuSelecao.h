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
                void exec();
                void desenhar();
                void executar();
                const bool HaDoisJogadores();
        };
    }
    
}