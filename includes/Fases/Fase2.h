#pragma once
#include "Fase.h"

namespace Fases {

    class Fase2 : public Fase {

        public:

            Fase2(bool coop = 0); //setar jogadores em obstaculos e inimigos;
            ~Fase2();

            void criaFundo();
            void setCaminho(std::string caminhoArq);
            void atualizar();
            void desenhar();
            //sf::Sprite criaSprites(); //implementar
    };
}