#pragma once
#include "Plataforma.h"

using namespace Entidades::Personagens;

namespace Entidades{
    namespace Obstaculos{
        class PlataformaGelo: public Obstaculo{

            private:
                bool deslizante;

            public:
                PlataformaGelo(); 
                PlataformaGelo(int x, int y);
                ~PlataformaGelo();
                void obstacular(Jogador* jogad);
                void executar();
        };
    }


}
