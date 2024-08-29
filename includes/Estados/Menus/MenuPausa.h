#include "Menu.h"
#include "../../Fase/Fase.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPausa: public Menu
        {
            private:
                Fases::Fase* fase;
                
            public:
                MenuPausa();
                ~MenuPausa(); 
                void executar(); 
                void desenhar();
        };
    }
    
}