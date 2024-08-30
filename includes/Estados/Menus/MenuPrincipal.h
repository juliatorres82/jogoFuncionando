#pragma once
#include "Menu.h"

namespace Estados
{
    namespace Menus
    {
        class MenuPrincipal: public Menu
        {
            private:
                 sf::Text titulo;
            public:
                MenuPrincipal();
                virtual ~MenuPrincipal(); 
                void exec(); 
                void desenhar();
                void executar();
                void setTitulo(const string &texto);
                void setPosTitulo(const sf::Vector2f &pos);        
                void setCorTitulo(const sf::Color &cor);
                void setTamTitulo(const unsigned int &tam);
        };
    }
    
}
