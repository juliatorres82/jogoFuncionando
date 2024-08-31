#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {
    class Gosma : public Obstaculo {

    private:
        const float viscosidade;
    
    public:
        Gosma (int posx = 0, int posy = 0);
        ~Gosma();

        void executar();
        void obstacular(Entidades::Personagens::Jogador* jogd);
        void gruda(); //implementar

};

}