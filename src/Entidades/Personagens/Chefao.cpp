#include "../../../includes/Entidades/Personagens/Chefao.h"
//#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h" 

Chefao::Chefao(float x, float y) : Inimigo(x,y) {
    atirar = false;
    projeteis = nullptr;
    pGC = pGC->getInstancia();
    pGG = pGG->getInstancia();
}


Chefao::~Chefao() {

   //if(projeteis != nullptr)
       // delete projeteis;
    projeteis = nullptr; 
}


void Chefao::atacar() {
    cout << "atacaar cheg" << endl;

    if(projeteis == nullptr)
        projeteis = new Projetil(corpo.getPosition(), 2.0f);

    cout << " aquiii no chefaooo " <<endl;
    if (!(pGC->haColisao(projeteis, jogador1))) {  // se não colidir com o jogador 


    cout << " uai " << endl;
        if(jogador2==NULL){ // e só houver ele 
            cout << " hola "  <<endl;
            sf::Vector2f posJogador(jogador1->getPosicaox(), jogador1->getPosicaoy());
            cout << " hola 2" <<endl;
            projeteis->setDirecao(posJogador - projeteis->getPosicao());
            cout << " hola 3" <<endl;
            projeteis->executar();
            cout << "executou o projetil" << endl;
        }
        else{
            cout << "hum " <<endl;

            if (!(pGC->haColisao(projeteis, jogador2))){
                cout << " holaqtral "  <<endl;

                if(rand()%2){
                    cout << "1" << endl;
                    sf::Vector2f posJogador(jogador1->getPosicaox(), jogador1->getPosicaoy());
                    cout << "2" << endl;
                    projeteis->setDirecao(posJogador - projeteis->getPosicao());
                    cout << "3" << endl;
                    projeteis->executar();
                    cout << "4" << endl;
                }
                else{
                    cout << "5" << endl;
                    sf::Vector2f posJogador(jogador2->getPosicaox(), jogador2->getPosicaoy());
                    cout << "6" << endl;
                    projeteis->setDirecao(posJogador - projeteis->getPosicao());
                    cout << "7" << endl;
                    projeteis->executar();
                    cout << "8" << endl;
                }
            }

        }
        cout << " ssssaaa" <<endl;
    }

    else
    {
        projeteis->parar();
        pGC->retiraProjetil(projeteis);
        delete projeteis;
    }
}

void Chefao:: executar(){
    cout << "entrou aqui no chefao" << endl;
    atacar();
    cout << "atacou" << endl;
    desenhar();
}