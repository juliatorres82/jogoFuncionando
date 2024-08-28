#pragma once
#include "Obstaculo.h"
#include "../Personagens/Jogador.h"

using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

class Gosma : public Obstaculo {

    private:
        bool grudar;
        Jogador* jog; // Gosma causa dano em (associação simples)
    
    public:
        Gosma();
        Gosma (int posx, int posy);
        ~Gosma();
        void executar();
        void obstacular(Jogador* joga);
};