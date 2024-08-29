#pragma once
#include "Obstaculo.h"
#include "Plataforma.h"
#include "../Personagens/Jogador.h"
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
