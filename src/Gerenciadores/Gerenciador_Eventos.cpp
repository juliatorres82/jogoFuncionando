#include "../../includes/Gerenciadores/Gerenciador_Eventos.h"
#include "../../includes/Gerenciadores/Gerenciador_Inputs.h"

namespace Gerenciadores
{
    Gerenciador_Eventos* Gerenciador_Eventos::pGE = nullptr;
    Gerenciador_Grafico* Gerenciador_Eventos::pGG = nullptr;
    Gerenciador_Inputs* Gerenciador_Eventos::pGI = nullptr;

    Gerenciador_Eventos::Gerenciador_Eventos(){
            pGG = Gerenciador_Grafico::getInstancia();
            pGI = Gerenciador_Inputs::getInstancia();
    }

    Gerenciador_Eventos::~Gerenciador_Eventos(){

        if(pGE)
            delete pGE;
        pGE = nullptr;

    }

    Gerenciador_Eventos* Gerenciador_Eventos::getGerenciadorEventos(){

        if(pGE == nullptr){ // se ainda não instanciado 
            pGE = new Gerenciador_Eventos();
        }
        return pGE;

    }

    void Gerenciador_Eventos::gerenciaEventos(){

        if(pGG){
            if(pGG->getJanela()->isOpen()){
                    while(pGG->getJanela()->pollEvent(evento)){
                    
                        if(evento.type == sf::Event::KeyPressed) //trocar depois apenas por if; excluir de cima
                            pGI->gerenciaTeclasPressionadas(evento.key.code);

                        else if (evento.type == sf::Event::KeyReleased)
                            pGI->gerenciaTeclasSoltas(evento.key.code);
                        
                        else if(evento.type == sf::Event::Closed) 
                            pGG->fecharJanela();
                }
            }
        }
    }
}