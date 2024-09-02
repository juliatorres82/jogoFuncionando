#include "../../includes/Observadores/Observador.h"


namespace Gerenciadores
{
    Gerenciador_Inputs* Gerenciador_Inputs:: gI = nullptr;
    Gerenciador_Grafico* Gerenciador_Inputs:: pGG = Gerenciador_Grafico::getInstancia();
    Gerenciador_Eventos* Gerenciador_Inputs:: pGE = Gerenciador_Eventos::getInstancia();

    Gerenciador_Inputs::Gerenciador_Inputs(){
    
        list<Observadores::Observador*>::iterator it = observadoresVigiando.begin();
        while(it != observadoresVigiando.end())
        {
            observadoresVigiando.erase(it);
            it++;
        
        }

    }

    Gerenciador_Inputs::~Gerenciador_Inputs() {
        
        list<Observadores::Observador*>::iterator it = observadoresVigiando.begin();
        while(it != observadoresVigiando.end())
        {
            observadoresVigiando.erase(it);
            it++;
        }

        if(gI != nullptr)
        {
            delete gI;
            gI = nullptr;
        }
    }

    Gerenciador_Inputs* Gerenciador_Inputs::getInstancia() {
        if (gI == nullptr) {
            gI = new Gerenciador_Inputs();
        }
        return gI;
    }

    void Gerenciador_Inputs::deletaInstancia()
    {
        if (gI != nullptr) {
            delete gI;
            gI = nullptr;
        }
    }

    void Gerenciador_Inputs::addObservadoresVigiando(Observadores::Observador* obs){
        
        if(obs != nullptr)
        {
        observadoresVigiando.push_back(obs);
        }

        else
        {
            std::cerr << "Erro ao adicionar observador ao Gerenciador de Inputs" << std::endl;
        }
    }


    void Gerenciador_Inputs::tiraObservadoresVigiando(Observadores::Observador* obs){
   
        if(obs != nullptr)
        {
            list<Observadores::Observador*>::iterator it = observadoresVigiando.begin();
            if(it == observadoresVigiando.end() || observadoresVigiando.empty())
            {
                return;
            }
            while(it != observadoresVigiando.end())
            {
                if(*it == obs)
                {
                    observadoresVigiando.erase(it);
                    return;
                }
                it++;
            }
        }
    }


    void Gerenciador_Inputs::gerenciaTeclasPressionadas(sf::Keyboard::Key tecla){
    
        std::list<Observadores::Observador*>::iterator itObs = observadoresVigiando.begin();
        
        for(itObs; itObs != observadoresVigiando.end(); itObs++) 
        {   if((*itObs)->getEstadoAtivo())
            {
                (*itObs)->notificaTeclaPressionada(tecla);
                
            }
        }   
            
    }


    void Gerenciador_Inputs::gerenciaTeclasSoltas(sf::Keyboard::Key tecla){

        std::list<Observadores::Observador*>::iterator itObs = observadoresVigiando.begin();

        for(itObs; itObs!=observadoresVigiando.end(); itObs++) 
        {   if((*itObs)->getEstadoAtivo())
            {
                (*itObs)->notificaTeclaSolta(tecla);
            }
        }
    
    }

}