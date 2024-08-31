#pragma once

#include "../Obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
            private:

                const float elasticidade;
                bool empuxo;

            public:
                Plataforma();
                Plataforma(int x = 0, int y = 0, float e = 0.5);
                //Plataforma(sf:: Vector2f posicao, int e, sf::Vector2f tam);
                ~Plataforma();
                void setElasticidade(float e);
                //void setTamanho(sf::Vector2f tam);
                
                void executar();
                void obstacular(Jogador* j1);
                void fazEmpuxo();
        };
    }
}

		
            
        