#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuRank: public Menu
        {

            private:
                list<sf::Text> rank;  
                
            public:
                MenuRank();
                void executar();
                void desenhar();
        };
    }
    
}   