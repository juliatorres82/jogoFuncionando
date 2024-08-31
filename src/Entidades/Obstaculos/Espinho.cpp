#include "../../../includes/Entidades/Obstaculos/Espinho.h"


Espinho:: Espinho(int posx, int posy): danoEspinhar(1) {
    corpo.setPosition(posx, posy);
}


Espinho:: ~Espinho() {}