#include "../../includes/Fases/Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;

Fase::Fase(bool coop) : Ente(fase) {
    cout << "Fase::Fase() funcionando" << endl;
    fundo.setSize(sf::Vector2f(pGG->getTamx(), pGG->getTamy()));
    ehCoop = coop;
    cout << "Fase::Fase() funcionando" << endl;
    listaJogadores = new ListaEntidades();
    listaInimigos = new ListaEntidades();
    listaObstaculos = new ListaEntidades();
    listaPlataforma = new ListaEntidades();
    cout << "Fase::Fase() funcionando" << endl;
    //setCaminho(caminho);
    //printf("Fase::Fase() funcionando\n"); ok
}

Fase::~Fase() {

    cout << "Fase::~Fase()" << endl;
    pGC->limpar();
    /* desalocando jogadores*/
    Lista<Entidade>::Iterador it = listaJogadores->getInicio();
    Entidade* pE = nullptr;
    cout << "Fase::~Fase() - desalocando jogadores" << endl;
    while(!it.isNulo()){
       pE = (*it);
        cout << "Fase::~Fase() - desalocando jogadores" << endl;
       if(pE != nullptr)
        delete pE;
        cout << "Fase::~Fase() - desalocando jogadores" << endl;
       pE = nullptr;
       ++it;
    }
    listaJogadores->limpar();
    cout << "Fase::~Fase() - desalocou jogadores" << endl;
   /* desalocando inimigos*/
    it = listaInimigos->getInicio();
    cout << "Fase::~Fase() - desalocando inimigos" << endl;
    while(!it.isNulo()){
       pE = (*it);

       if(pE != nullptr)
        delete pE;

       pE = nullptr;
       ++it;
    }
    listaInimigos->limpar();
    cout << "Fase::~Fase() - desalocou inimigos" << endl;

    cout << "Fase::~Fase() - desalocando obstaculos" << endl;
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

    cout << "Fase::~Fase() - desalocando plataformas" << endl;
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
    jogador1 = new Jogador(64,64);
    listaJogadores->incluir(jogador1);
    pGC->incluirJogador(jogador1);
    cout << jogador1->doisJogadores() << endl;
    if(ehCoop){
        Jogador* jogador2 = nullptr;
        jogador2 = new Jogador(68,68);
        listaJogadores->incluir(jogador2);
        jogador1->setJogador2(jogador2);
        jogador2->setJogador2(jogador1);
        jogador2->setQJog();
        pGC->incluirJogador(jogador2);
    }
    cout << jogador1->doisJogadores() << endl;
}


void Fase:: criarTudo(int posx, int posy, int valor) {

       switch (valor) {

                    case 0:
                        break;

                    case 23: {
                        Plataforma* plataforma = new Plataforma(posx, posy);
                        listaPlataforma->incluir(plataforma);
                        pGC->incluirObstaculos(plataforma);
                        cout << "Plataforma criada" << endl;
                        break;
                    } 
                    case 47: {
                        PlataformaGelo* plataformaGelo = new PlataformaGelo(posx, posy);
                        listaPlataforma->incluir(plataformaGelo);
                        pGC->incluirObstaculos(plataformaGelo);
                        cout << "Plataforma de gelo criada" << endl;
                        break;
                    }
            
                    case 32: {
                        Espinho* espinho = new Espinho(posx, posy);
                        listaObstaculos->incluir(espinho);
                        pGC->incluirObstaculos(espinho);
                        cout << "Espinho criado" << endl;
                        break;
                    }
                    case 43: {
                        Fantasma* fantasma = new Fantasma(posx, posy);
                        listaInimigos->incluir(fantasma);
                        pGC->incluirInimigos(fantasma);
                        cout << "Fantasma criado" << endl;
                        break;
                    }
                    case 25: {
                        Lagarto* lagarto = new Lagarto(posx, posy);
                        listaInimigos->incluir(lagarto);
                        pGC->incluirInimigos(lagarto);
                        cout << "Lagarto criado" << endl;
                        break;
                    }
                    case 29: {
                        Gosma* gosma = new Gosma(posx, posy);
                        listaObstaculos->incluir(gosma);
                        pGC->incluirObstaculos(gosma);
                        cout << "Gosma criada" << endl;
                        break;
                    }
                    case 16: {
                        Chefao* chefao = new Chefao(posx, posy);
                        listaInimigos->incluir(chefao);
                        pGC->incluirInimigos(chefao);
                        cout << "Chefao criado" << endl;
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
    
    return matrizMapa;
}

void Fase:: constroiFase() {

    criaJogadores();
    
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
    
}


void Fase:: tratarColisoes() {
    pGC->tratarColisoes();
}

void Fases::Fase::executar(){

    desenhar();
   
    atualizar();

    tratarColisoes();

}

void Fases::Fase::atualizar()
{
    listaJogadores->executaLista();
    listaInimigos->executaLista();
    listaObstaculos->executaLista();
    listaPlataforma->executaLista();
}
void Fases::Fase::setsJogadores()
{
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
 void Fases::Fase::desenhar(){
    pGG->desenhar(fundo);
    listaJogadores->desenhaLista();
    listaInimigos->desenhaLista();
    listaObstaculos->desenhaLista();
    listaPlataforma->desenhaLista();
 }