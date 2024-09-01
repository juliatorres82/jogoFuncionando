#pragma once
#include "Plataforma.h"

using namespace Entidades::Personagens;

namespace Entidades{
    namespace Obstaculos{
        class PlataformaGelo: public Obstaculo{

            private:
                const float deslizo;

            public:
                PlataformaGelo(int x = 0, int y = 0);
                ~PlataformaGelo();
                void obstacular(Jogador* jogad);
                void fazEmpuxo();
                void executar();
        };
    }


}
