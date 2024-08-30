#include "../../../includes/Entidades/Obstaculos/PlataformaGelo.h"
#include "PlataformaGelo.h"

using namespace Entidades;
using namespace Obstaculos;

PlataformaGelo::PlataformaGelo(int posx, int posy): deslizo(0.5) {
    corpo.setPosition(posx, posy);
}

PlataformaGelo::~PlataformaGelo() {}
void Entidades::Obstaculos::PlataformaGelo::deslizaJogador(Jogador *j1)
{
}