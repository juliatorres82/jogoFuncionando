#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {

    class Espinho : public Obstaculo {

        private:
            bool espinhar;
        
        public:
            Espinho();
            Espinho(int posx, int posy);
            ~Espinho();
            
            void executar();
            void obstacular(Entidades::Personagens::Jogador* jogd);
    };
}