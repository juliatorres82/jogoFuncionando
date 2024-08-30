#pragma once
#include "Estado.h"
#include "../Fases/Fase.h"

namespace Estados
{
    class Jogando : public Estados::Estado
    {
        private:
            Fases::Fase* fase;
        public:
            Jogando(const std::string& id = "Jogando");
            ~Jogando();
            void criaFase(bool coop);
            void exec();
            void atualizar();
    };
}