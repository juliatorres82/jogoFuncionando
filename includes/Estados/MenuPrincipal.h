#pragma once
#include "Menu.h"

class MenuPrincipal: public Menu
{
    private:
        bool doisJogadores;
    public:
        MenuPrincipal();
        virtual ~MenuPrincipal(); 
        void exec(); ////
        void setDoisJogadores();
        const bool HaDoisJogadores();
};