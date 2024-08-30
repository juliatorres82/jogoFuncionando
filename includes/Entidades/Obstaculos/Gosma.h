#pragma once
#include "Obstaculo.h"

namespace Entidades::Obstaculos {
    class Gosma : public Obstaculo {

        private:
            bool grudar;
        
        public:
            Gosma();
            Gosma (int posx, int posy);
            ~Gosma();
            void executar();
            void obstacular(Entidades::Personagens::Jogador* joga);
    };
}