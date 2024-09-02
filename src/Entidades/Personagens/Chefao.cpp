#include "../../../includes/Entidades/Personagens/Chefao.h"
//#include "../../../includes/Gerenciadores/Gerenciador_Colisoes.h" 

Chefao::Chefao(float x, float y) : Inimigo(x,y) {
    atirar = false;
    projeteis = nullptr;
    pGC = pGC->getInstancia();
    pGG = pGG->getInstancia();
    jogador1 = nullptr;
    jogador2 = nullptr;
}


Chefao::~Chefao() {

   if(projeteis != nullptr)
        delete projeteis;
    projeteis = nullptr; 
    jogador1 = nullptr;
    jogador2 = nullptr;

}


void Chefao::atacar() {

    if(projeteis == nullptr)
        projeteis = new Projetil(corpo.getPosition(), 2.0f);

    if (!(pGC->haColisao(projeteis, jogador1))) {  // se não colidir com o jogador 


        if(jogador2 == nullptr){ // e só houver ele 
       
            sf::Vector2f posJogador(jogador1->getPosicaox(), jogador1->getPosicaoy());
          
            projeteis->setDirecao(posJogador - projeteis->getPosicao());
           
            projeteis->executar();
            
        }
        else{
            
            if (!(pGC->haColisao(projeteis, jogador2))){
                

                if(rand()%2){
                   
                    sf::Vector2f posJogador(jogador1->getPosicaox(), jogador1->getPosicaoy());
                    
                    projeteis->setDirecao(posJogador - projeteis->getPosicao());
                    
                    projeteis->executar();
                   
                }
                else{
                
                    sf::Vector2f posJogador(jogador2->getPosicaox(), jogador2->getPosicaoy());
                    
                    projeteis->setDirecao(posJogador - projeteis->getPosicao());
                 
                    projeteis->executar();
                  
                }
            }

        }
        
    }

    else
    {
        projeteis->parar();
        pGC->retiraProjetil(projeteis);
        delete projeteis;
    }
}

void Chefao:: executar(){
    
    atacar();
    desenhar();
}