#pragma once
#include "Inimigo.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

class Lagarto : public Inimigo {

    private:
        bool perseguidor;
        Jogador* jog1;

    public:
        Lagarto();
        Lagarto(float x, float y);
        ~Lagarto();
        void perseguir(); 
        void mover();
        void executar(); //




};