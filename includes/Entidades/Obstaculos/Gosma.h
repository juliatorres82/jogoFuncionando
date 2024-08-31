#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {
    class Gosma : public Obstaculo {

    private:
        const float viscosidade;
    
    public:
        Gosma (int posx, int posy);
        ~Gosma();

        void executar();
        void obstacular(Entidades::Personagens::Jogador* jogd);
        void gruda(); //implementar

};

}