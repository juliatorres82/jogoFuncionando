#pragma once
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
        void ficarVisivel();
        bool isInvisivel();
        void mover();
        void executar();
};