#include "../../includes/Fases/Fase1.h"

Fases::Fase1::Fase1(bool coop)
{
    caminho = "mapinha.tmj";
    setCaminho(caminho);
}

Fases::Fase1::~Fase1()
{
}   

void Fases::Fase1::criaFundo(){
    sf::Texture fundo;

    if(!fundo.loadFromFile("imagens/fundo.png")) {
        std::cerr << "Erro ao carregar a textura do fundo" << std::endl;
    }
    pGG->desenhar(fundo);
}   

void Fases::Fase1::setCaminho(std::string caminhoArq){ //arquivo json do mapa
    caminho = caminhoArq;
}

void Fases::Fase1::atualizar(){
    listaJogadores->executaLista();
    listaInimigos->executaLista();
    listaObstaculos->executaLista();
    //listaPlataforma->executaLista();
}

void Fases::Fase1::executar(){
    tratarColisoes();
    tratarEventos();
}

/*void Fases::Fase1::desenhar(){ //com sprites:
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}
*/

void Fases::Fase1::desenhar(){

    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    //listaPlataforma->desenhaLista();
}

//sf::Sprite Fases::Fase1::criaSprites(){} //implementar
