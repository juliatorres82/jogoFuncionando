#pragma once
#include "Plataforma.h"

using namespace Entidades::Personagens;

namespace Entidades{
    namespace Obstaculos{
        class PlataformaGelo: public Obstaculo{

            private:
                const float deslizo;

            public:
                PlataformaGelo(); 
                PlataformaGelo(int x, int y);
                ~PlataformaGelo();
                void obstacular(Jogador* jogad);
                void fazEmpuxo();
                void executar();
        };
    }


}
