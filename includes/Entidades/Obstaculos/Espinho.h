#pragma once
#include "Obstaculo.h"

using namespace Entidades::Obstaculos;

class Espinho : public Obstaculo {

    private:
        const int danoEspinhar;
    
    public:
        Espinho(int posx, int posy);
        ~Espinho();
        void Espinhar(); //da dano se tocar ---- implementar
};