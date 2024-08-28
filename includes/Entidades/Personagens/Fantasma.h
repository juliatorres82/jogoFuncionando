#pragma once
#include "Jogador.h"

using namespace Entidades::Personagens;

class Fantasma : public Inimigo {

    private:

        bool invisivel;

    public:

        Fantasma();
        Fantasma(float x, float y);
        ~Fantasma();
        void perseguir();
        void ficarInvisivel();
        void ficarVisivel();
        bool isInvisivel();
        void mover();
        void executar();
        void atacar();
};