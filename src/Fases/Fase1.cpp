#include "../../includes/Fases/Fase1.h"

Fases::Fase1::Fase1(bool coop)
{
    caminho = "../mapao.tmj";
    setCaminho(caminho);
    criaFundo();
    constroiFase();
}

Fases::Fase1::~Fase1()
{
}   

void Fases::Fase1::criaFundo(){
    sf::Texture fundo;

    if(!fundo.loadFromFile("../imagens/imagemFundo.jpeg")) {
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
