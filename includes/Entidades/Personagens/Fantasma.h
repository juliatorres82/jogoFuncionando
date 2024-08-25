#pragma once
#include "Inimigo.h"
#include "Jogador.h"

using namespace Entidades::Personagens;

class Fantasma : public Inimigo {

    private:

        bool invisivel;
    
    public:

        Fantasma();
        ~Fantasma();
        void perseguir();
        void ficarInvisivel();
        bool isInvisivel();
        void mover();
};