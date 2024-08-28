#pragma once
#include <cmath>
#include "Inimigo.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

class Lagarto : public Inimigo {

    private:
        float frequencia;
        float amplitude;

    public:
        Lagarto();
        Lagarto(float x, float y);
        ~Lagarto();
        void mover();
        void executar(); //
        void atacar();




};