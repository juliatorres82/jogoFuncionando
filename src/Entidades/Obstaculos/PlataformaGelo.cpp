#include "../../../includes/Entidades/Obstaculos/PlataformaGelo.h"

using namespace Entidades;
using namespace Obstaculos;

PlataformaGelo::PlataformaGelo(int posx, int posy) {
    corpo.setPosition(posx, posy);
}

PlataformaGelo:: ~PlataformaGelo() {}