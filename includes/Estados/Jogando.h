#pragma once
#include "Estado.h"
#include "../Fase/Fase1.h"
#include "../Fase/Fase2.h"

namespace Observadores
{
    class ObservadorJogador;
}
namespace Estados
{
    class Jogando : public Estados::Estado
    {
        private:
            Fases::Fase* fase;
            Observadores::ObservadorJogador* observadorJogador;
        public:
            Jogando(const std::string& id = "Jogando");
            ~Jogando();
            void criaFase(bool coop);
            void exec();
            void atualizar();
            void pausar();
    };
}