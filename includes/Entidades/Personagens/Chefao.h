#pragma once
#include "Jogador.h"
#include "Projetil.h"

using namespace Entidades::Personagens;

class Chefao : public Inimigo {

    private:

            bool atirar;
            Projetil* projeteis;
            
        public:
            Chefao(float x, float y);
            ~Chefao();
            void atacar();
            void executar();
};