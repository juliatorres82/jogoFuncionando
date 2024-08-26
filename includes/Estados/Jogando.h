#include "Estado.h"
#include "../Fase/Fase.h"

class Jogando : public Estados::Estado
{
    private:
        Fases::Fase* fase;
    public:
        Jogando();
        ~Jogando();
        void exec();
        void atualizar();
};