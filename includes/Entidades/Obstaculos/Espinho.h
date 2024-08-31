#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {

    class Espinho : public Obstaculo {

    private:
        const int danoEspinhar;
    
    public:
        Espinho();
        Espinho(int posx, int posy);
        ~Espinho();

        void executar();
        void obstacular(Entidades::Personagens::Jogador* jogd);
        void Espinhar(); //da dano se tocar ---- implementar
};

}