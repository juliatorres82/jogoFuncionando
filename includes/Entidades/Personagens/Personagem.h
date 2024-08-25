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
			    bool colidindo;


            public:
                Personagem();
                ~Personagem();
                virtual void mover();
			    void pular(float pulo);
                void mudaColidindo(bool flagColid);
        };
    }
}

