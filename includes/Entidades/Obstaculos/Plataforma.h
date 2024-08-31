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

                const float elasticidade;
                //Gerenciador_Grafico* pGG;

            public:
                Plataforma();
                Plataforma(float x, float y);
                Plataforma(sf:: Vector2f posicao, int e, sf::Vector2f tam);
                ~Plataforma();
                void setTamanho(sf::Vector2f tam);
                void executar();
                void obstacular();
        };
    }
}

		
            
        