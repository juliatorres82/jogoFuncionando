#include "../../includes/Fases/Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;

Fase::Fase(bool coop) {
    fundo.setSize(sf::Vector2f(pGG->getTamx(), pGG->getTamy()));
    ehCoop = coop;
    listaJogadores = new ListaEntidades();
    listaInimigos = new ListaEntidades();
    listaObstaculos = new ListaEntidades();
    listaPlataforma = new ListaEntidades();

    pGG = pGG->getInstancia();
    pGC = pGC->getInstancia();
    p_GE = p_GE->getGerenciadorEventos();
    //setCaminho(caminho);
    //printf("Fase::Fase() funcionando\n"); ok
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

                    case 0:
                        break;

                    case 18: {
                        cout << "criou plataforma" << endl;
                        Plataforma* plataforma = new Plataforma(posx, posy);
                        listaPlataforma->incluir(plataforma);
                        pGC->incluirObstaculos(plataforma);
                        break;
                    } 
                    case 23: {
                        cout << "criou plataforma de gelo" << endl;
                        PlataformaGelo* plataformaGelo = new PlataformaGelo(posx, posy);
                        listaPlataforma->incluir(plataformaGelo);
                        pGC->incluirObstaculos(plataformaGelo);
                        break;
                    }
                    case 1: {
                        cout << "criou jogador" << endl;
                        Jogador* jogador = new Jogador(posx, posy);
                        listaJogadores->incluir(jogador);
                        pGC->incluirJogador(jogador);
                        break;
                    }
                    case 14: {
                        cout << "criou espinho" << endl;
                        Espinho* espinho = new Espinho(posx, posy);
                        listaObstaculos->incluir(espinho);
                        pGC->incluirObstaculos(espinho);
                        break;
                    }
                    case 49: {
                        cout << "criou fantasma" << endl;
                        Fantasma* fantasma = new Fantasma(posx, posy);
                        listaInimigos->incluir(fantasma);
                        pGC->incluirInimigos(fantasma);
                        break;
                    }
                    case 43: {
                        cout << "criou lagarto" << endl;
                        Lagarto* lagarto = new Lagarto(posx, posy);
                        listaInimigos->incluir(lagarto);
                        pGC->incluirInimigos(lagarto);
                        break;
                    }
                    case 12: {
                        cout << "criou gosma" << endl;
                        Gosma* gosma = new Gosma(posx, posy);
                        listaObstaculos->incluir(gosma);
                        pGC->incluirObstaculos(gosma);
                        break;
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
    cout << "processou mapa "  <<endl;
    return matrizMapa;
}

void Fase:: constroiFase() {

    cout <<"entrou em constroiFase()"<<endl;
    vector<vector<vector<int>>> matriz = converteJsonParaMatriz(caminho, 1);
    
    for(int i = 0; i < matriz.size(); i++){
		for(int j = 0; j < matriz[i].size(); j++){
			for (int k = 0; k < matriz[i][j].size(); k++) {
				criarTudo(k * 32,  j* 32, matriz[i][j][k]);
                
			}
		}
	}
    //setar jogs em obstacular e inimigos
    setsJogadores();
    cout << "saiu de constroiFase()"<<endl;
}

/*void Fase:: constroiFase(){
    Plataforma* p = new Plataforma(32,32);
    //Plataforma* p2 = new Plataforma(64,32);
    //Plataforma* p3 = new Plataforma(96,32);
    //Plataforma* p4 = new Plataforma(128,32);
    //Plataforma* p5 = new Plataforma(100,32);
    //Plataforma* p6 = new Plataforma(132,32);

    Jogador* j1 = new Jogador(60, 60);
    Fantasma* f1 = new Fantasma(100, 100);

}*/

void Fase:: tratarColisoes() {
    pGC->tratarColisoes();
}

void Fase::atualizar() 
{

}

void Fases::Fase::executar(){
    //printf("entrou em executarFase\n"); 

    desenhar();
    atualizar();
    tratarColisoes();
}

void Fases::Fase:: setsJogadores(){
    Lista<Entidade>::Iterador it = listaJogadores->getInicio();
    Lista<Entidade>::Iterador it2 = listaInimigos->getInicio();
    if(it.isNulo()){
        cout << "Lista de jogadores vazia" << endl;
        return;
    }
    while(!it2.isNulo()){
        Entidade* pE = (*it2);
        Inimigo* inimigo = dynamic_cast<Inimigo*>(pE);
        inimigo->setJogador(static_cast<Jogador*>(*it));
        ++it2;
    }

    it2 = listaObstaculos->getInicio();

    while(!it2.isNulo()){
        Entidade* pE = (*it2);
        Obstaculo* obstaculo = dynamic_cast<Obstaculo*>(pE);
        obstaculo->setJogadorPDano(static_cast<Jogador*>(*it));
        ++it2;
    }
}

ListaEntidades* Fase::getListaJogadores(){
    return listaJogadores;
}

Jogador* Fase::getJogador1(){
    if(listaJogadores->getPrimeiro() == nullptr){
        cout << "Jogador 1 não encontrado" << endl;
        return nullptr;
    }
    return static_cast<Jogador*>(listaJogadores->getPrimeiro());
}

Jogador *Fases::Fase::getJogador2()
{
    if(ehCoop){
        Lista<Entidade>::Iterador it = listaJogadores->getInicio();
        it.operator++();
        if(it.isNulo()){
            cout << "Jogador 2 não encontrado" << endl;
            return nullptr;
        }
        return static_cast<Jogador*>(*it);
    }
    return nullptr;
}
