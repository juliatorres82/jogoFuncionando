#pragma once

#include "../Obstaculos/Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma :
            public Obstaculo
        {
            private:

                int elasticidade;
                //Gerenciador_Grafico* pGG;

            public:
                Plataforma();
                Plataforma(sf:: Vector2f posicao, int e, sf::Vector2f tam);
                ~Plataforma();
                void setElasticidade(int e);
                void setTamanho(sf::Vector2f tam);
                void executar();
                void obstacular();
        };
    }
}

		
            
        