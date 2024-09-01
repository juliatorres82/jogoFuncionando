#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {

    class Espinho : public Obstaculo {

    private:
        const int danoEspinhar;
    
    public:
        Espinho(int posx = 0, int posy = 0);
        ~Espinho();

        void executar();
        void obstacular(Entidades::Personagens::Jogador* jogd);
};

}