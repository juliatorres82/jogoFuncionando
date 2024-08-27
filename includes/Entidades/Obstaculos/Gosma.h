#pragma once
#include "Obstaculo.h"

using namespace Entidades::Obstaculos;

class Gosma : public Obstaculo {

    private:
        bool grudar;
    
    public:
        Gosma (int posx, int posy);
        ~Gosma();
        void gruda(); //implementar

};