#include "../../includes/Fases/Fase1.h"

Fases::Fase1::Fase1(bool coop)
{
    caminho = "../mapao.tmj";
    setCaminho(caminho);
    criaFundo();
    constroiFase();
    desenhar();
}

Fases::Fase1::~Fase1()
{
}   

void Fases::Fase1::criaFundo(){
    cout << "criando fundo" << endl;
    sf::Texture fundo;

    try{
        fundo.loadFromFile("../imagens/imagemFundo.jpeg");
    }
   catch (const std::bad_alloc& e){
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
    listaPlataforma->executaLista();
}

/*void Fases::Fase1::desenhar(){ //com sprites:
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
}
*/

void Fases::Fase1::desenhar(){
    //cout << "desenhando" << endl;
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
    //cout << "desenhou" << endl;
}

//sf::Sprite Fases::Fase1::criaSprites(){} //implementar
