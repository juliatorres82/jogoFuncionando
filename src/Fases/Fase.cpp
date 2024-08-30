#include "../../includes/Fase/Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;

Fase::Fase(bool coop) {
    ehCoop = coop;
    listaJogadores = new ListaEntidades();
    listaInimigos = new ListaEntidades();
    listaObstaculos = new ListaEntidades();
    listaPlataforma = new ListaEntidades();

    pGG = pGG->getInstancia();
    //setCaminho(caminho);
}

Fase::~Fase() {

    /* desalocando jogadores*/
    Lista<Entidade>::Iterador it = listaJogadores->getInicio();
    Entidade* pE = nullptr;

    while(!it.isNulo()){
       pE = (*it);

       if(pE != nullptr)
        delete pE;

       pE = nullptr;
       ++it;
    }
    listaJogadores->limpar();


   /* desalocando inimigos*/
    it = listaInimigos->getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != nullptr)
        delete pE;

       pE = nullptr;
       ++it;
    }
    listaInimigos->limpar();


    /* desalocando obstaculos*/
    it = listaObstaculos->getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != nullptr)
        delete pE;

       pE = nullptr;
       ++it;
    }

    listaObstaculos->limpar();


     /* desalocando plataformas*/
    it = listaPlataforma->getInicio();

    while(!it.isNulo()){
       pE = (*it);

       if(pE != nullptr)
        delete pE;

       pE = nullptr;
       ++it;
    }

    listaPlataforma->limpar();

}


void Fase:: criaJogadores(){

    Jogador* jogador1 = nullptr;
    jogador1 = new Jogador();
    listaJogadores->incluir(jogador1);

    if(ehCoop){
        Jogador* jogador2 = nullptr;
        jogador2 = jogador1->getJogador2();
        jogador2 = new Jogador();
        listaJogadores->incluir(jogador2);
        jogador1->setJogador2(jogador2);
        jogador2->setJogador2(jogador1);
    }
}

void Fase:: criarTudo(int posx, int posy, int valor) {

       switch (valor) {
        
                    case 0: // Tile vazio
                        break;
                    //case 23: {
                        //PlataformaGelo* plataformaGelo = new PlataformaGelo(posx, posy);
                        //listaPlataforma->incluir(plataformaGelo);
                        //break;
                    //}
                    case 34: {
                        Jogador* jogador = new Jogador(posx, posy);
                        listaJogadores->incluir(jogador);
                        break;
                    }
                    case 47: {
                        Espinho* espinho = new Espinho(posx, posy);
                        listaObstaculos->incluir(espinho);
                    }
                    case 49: {
                        Fantasma* fantasma = new Fantasma(posx, posy);
                        listaInimigos->incluir(fantasma);
                    }
                    case 29: {
                        Lagarto* lagarto = new Lagarto(posx, posy);
                        listaInimigos->incluir(lagarto);
                    }
                    case 18: {
                        Gosma* gosma = new Gosma(posx, posy);
                        listaObstaculos->incluir(gosma);
                    }
                    default:
                        break;
        }
}

    /* Feito por chatGPT, revisado e verificado pelos autores */
vector<vector<vector<int>>> Fase:: converteJsonParaMatriz(const std::string& caminhoArquivoJson, int numLayers){
    std::ifstream arquivo(caminhoArquivoJson);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo JSON.");
    }

    json mapa;
    arquivo >> mapa; //Lê arquivo JSON;

    if (numLayers > mapa["layers"].size()) {
        throw std::runtime_error("Quantidade de camadas maior do que a declarada no JSON.");
    }

    vector<vector<vector<int>>> matrizMapa;

    for (int i = 0; i < numLayers; i++) {
        auto camada = mapa["layers"][i];

        if (camada["type"] != "tilelayer") { // Verifica se a camada é do tipo tilelayer
            throw std::runtime_error("Camada encontrada não é do tipo 'tilelayer'.");
        }

        int largura = camada["width"];
        int altura = camada["height"];
        auto dados = camada["data"];

        vector<vector<int>> matriz(altura, vector<int>(largura, 0)); //Transforma JSON em matriz;

        for (int y = 0; y < altura; ++y) {
            for (int x = 0; x < largura; ++x) {
                matriz[y][x] = dados[y * largura + x];
            }
        }

        matrizMapa.push_back(matriz);
    }
    return matrizMapa;
}



void Fase:: constroiFase() {

    vector<vector<vector<int>>> matriz = converteJsonParaMatriz(caminho, 1);

    for(int i = 0; i < matriz.size(); i++){
		for(int j = 0; j < matriz[i].size(); j++){
			for (int k = 0; k < matriz[i][j].size(); k++) {
				criarTudo(k * 32,  j* 32, matriz[i][j][k]);
			}
		}
	}

}

void Fases::Fase::criaFundo()
{
}

void Fase:: tratarColisoes() {
    p_GC->tratarColisoes();
}

void Fases::Fase::tratarEventos()
{
    p_GE->gerenciaEventos();
}


void Fase::atualizar() {

    tratarEventos();
    tratarColisoes();
    desenhar();
}
