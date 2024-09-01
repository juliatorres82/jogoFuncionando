#pragma once
#include "Fase.h"

namespace Fases {

    class Fase1 : public Fase {

        public:

            Fase1(bool coop = 0); //setar jogadores em obstaculos e inimigos;
            ~Fase1();

            void criaFundo();
            void setCaminho(std::string caminhoArq);
            void desenhar();
            void executar();
            //sf::Sprite criaSprites(); //implementar
    };  
}