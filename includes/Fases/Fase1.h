#include "Fase.h"

namespace Fases
{
    class Fase1 : public Fases::Fase
    {
        private:
            ListaEntidades ListaLagartos;
            ListaEntidades ListaEspinhos;
            Fantasma fantasma1;
            Plataforma plataforma1;
            Plataforma plataforma2;
            Plataforma plataforma3;

        public:
            Fase1();
            ~Fase1();

            void inicializar();
            void criaInimFaceis();
            void criaEspinhos();
            void executar();
            void desenhar();
            
            void finalizar();
    };
}
