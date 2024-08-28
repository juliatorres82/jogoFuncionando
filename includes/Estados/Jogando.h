#pragma once
#include "Estado.h"
#include "../Fase/Fase1.h"
#include "../Fase/Fase2.h"

class Jogando : public Estados::Estado
{
    private:
        Fases::Fase* fase;
    public:
        Jogando();
        ~Jogando();
        void exec(bool coop);
        void atualizar();
        void criaFase1();
        void criaFase2();
};