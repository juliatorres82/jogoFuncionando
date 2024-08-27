#include "../../includes/Estados/MenuPrincipal.h"

MenuPrincipal :: MenuPrincipal() : doisJogadores(false) {}

MenuPrincipal :: ~MenuPrincipal() {}

const bool MenuPrincipal:: HaDoisJogadores() {
    return doisJogadores;
}

void MenuPrincipal:: setDoisJogadores(){
    doisJogadores = true;
}

void MenuPrincipal:: exec() {}