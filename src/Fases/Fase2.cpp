#include "../../includes/Fases/Fase2.h"

using namespace Fases;

Fase2::Fase2(bool coop) : Fase(coop) {
    caminho = "../elGrandeMapo.tmj";
    setCaminho(caminho);
    criaFundo();
    constroiFase();
}

Fase2::~Fase2() {
}

void Fase2::setCaminho(std::string caminhoArq) {
    caminho = caminhoArq;
}

void Fase2::executar() {

    cout << " entrou no executar f2" << endl;
    tratarColisoes();
    cout << " ger cooool " << endl;
    listaJogadores->executaLista();
    cout << " aaaqui " << endl;
    listaInimigos->executaLista(); //erro aqui no chefao
    cout << " aaaqui 2" << endl;
    listaObstaculos->executaLista();
    cout << " aaaqui 3" << endl;
    listaPlataforma->executaLista();

    cout << " executou f2" << endl;
}

void Fase2::desenhar() {

    pGG->desenhar(fundo);
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}

void Fase2::criaFundo() {

    try{
        textura_fundo.loadFromFile("../../imagens/imagemFundo.jpeg");
        if(!textura_fundo.loadFromFile("../../imagens/imagemFundo.jpeg")){
            throw std::bad_alloc();
        }
    }
   catch (const std::bad_alloc& e){
        std::cerr << "Erro ao carregar a textura do fundo" << std::endl;
    }

    fundo.setTexture(&textura_fundo);
}
/*
void Fases::Fase1::desenhar(){ //com sprites:
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}
*/