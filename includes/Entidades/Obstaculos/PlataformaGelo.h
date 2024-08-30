#pragma once
#include "Obstaculo.h"
#include "Plataforma.h"
#include "../Personagens/Jogador.h"
using namespace Entidades::Personagens;

namespace Entidades{
    namespace Obstaculos{
        class PlataformaGelo: public Plataforma{

            private:
                const float deslizo;

            public:
                PlataformaGelo(int x, int y);
                ~PlataformaGelo();
                void deslizaJogador (Jogador* j1); //faz velocidade do jogador aumentar
        };
    }


}
