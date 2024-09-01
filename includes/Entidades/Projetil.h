#pragma once
#include "Entidade.h"
#define dano 2

using namespace Entidades;

class Projetil : public Entidade {

    private:
        sf::Vector2f direcao;
        float velocidade;
        bool colidindo;

    public:
        Projetil(sf::Vector2f pos, float vel);
        ~Projetil();
        void mover();
        void executar();
        void desenhar();
        int causarDano();
        sf::Vector2f getPosicao();
        void setDirecao(sf::Vector2f dir);
        void parar();

};