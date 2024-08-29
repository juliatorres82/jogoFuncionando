#include "../../includes/Estados/Menus/MenuPausa.h"
#include "MenuPausa.h"

namespace Estados
{
    namespace Menus
    {
        MenuPausa::MenuPausa()
        {
        }

        MenuPausa::~MenuPausa()
        {
        }

        void MenuPausa::executar()
        {
            
        }
        void Menus::MenuPausa::desenhar()
        {
            fase->desenhar();
            pGG->desenhar(fundo);
            pGG->desenhar(titulo);

            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                (*it)->desenhar();
            }
        }
        
    }

    
}