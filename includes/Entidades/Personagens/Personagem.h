#pragma once
#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem :
            public Entidade
        {
            protected:
                int vidas;
                float velx;
                float vely;
                bool podePular;

            public:
                Personagem();
                Personagem(float x, float y);
                ~Personagem();
                virtual void mover();
                void pular(float pulo);
                void mudaPodePular(bool flagPodePular);
                virtual void parar();
                virtual void voltar() = 0;
                float getVelx() { return velx; };
                float getVely() { return vely; };
        };
    }
}

