#pragma once
#include "Obstaculo.h"

using namespace Entidades::Obstaculos;

class Gosma : public Obstaculo {

    private:
        const float viscosidade;
    
    public:
        Gosma (int posx, int posy);
        ~Gosma();
        void gruda(); //implementar

};