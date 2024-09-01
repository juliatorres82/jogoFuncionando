#include "Menu.h"
#include "../../Fases/Fase.h"

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
                void setFase(Fases::Fase *f);
                void exec();
                void executar(); 
                void desenhar();
        };
    }
    
}