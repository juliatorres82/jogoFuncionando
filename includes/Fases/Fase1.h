#include "Fase.h"

namespace Fases {

    class Fase1 : public Fase {

        public:

            Fase1(bool coop = 0);
            ~Fase1();

            void criaFundo();
            void setCaminho(std::string caminhoArq);
            void atualizar();
            void executar();
            void desenhar();
            //sf::Sprite criaSprites(); //implementar
    };  
}