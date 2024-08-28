#pragma once
#include "Estado.h"
#include "../Fase/Fase.h"

namespace Estados
{
    class Jogando : public Estados::Estado
    {
        private:
            Fases::Fase* fase;
        public:
            Jogando();
            ~Jogando();
            void criaFase();
            void exec();
            void atualizar();
    };
}