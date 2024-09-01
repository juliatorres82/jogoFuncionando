#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"

namespace Observadores
{
    class ObservadorJog;
}
namespace Estados
{
    class Jogando : public Estados::Estado
    {
        private:
            Fases::Fase* fase;
            Observadores::ObservadorJog* observadorJog;
            
        public:
            Jogando(const std::string& id = "Jogando");
            ~Jogando();
            void criaFase(bool coop);
            
            void exec();
            void atualizar();
            void pausar();
            Fases::Fase *getFase();
    };
}