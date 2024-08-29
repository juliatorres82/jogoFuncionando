#include "../../includes/Estados/MenuPrincipal.h"

Estados::MenuPrincipal :: MenuPrincipal() : doisJogadores(false) {}

Estados::MenuPrincipal :: ~MenuPrincipal() {}

const bool Estados::MenuPrincipal:: HaDoisJogadores() {
    return doisJogadores;
}

void Estados::MenuPrincipal:: setDoisJogadores(){
    doisJogadores = true;
}

void Estados::MenuPrincipal:: exec() {}