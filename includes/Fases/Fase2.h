#include "Fase.h"

namespace Fases
{
    class Fase2 : public Fases::Fase
    {
        private:
            ListaEntidades ListaInimFaceis;
            ListaEntidades ListaObstDificeis;
            Fantasma fantasma1;
            Plataforma plataforma1;
            Plataforma plataforma2;
            Plataforma plataforma3;
            
        public:
            Fase2();
            ~Fase2();

            void inicializar();
            
            void executar();
            void desenhar();
            
            void finalizar();
    };
}
