#include "../../../includes/Entidades/Obstaculos/Gosma.h"

Gosma:: Gosma (int posx, int posy): viscosidade(0.5) {
    corpo.setPosition(posx, posy);
}

Gosma:: ~Gosma() {}

