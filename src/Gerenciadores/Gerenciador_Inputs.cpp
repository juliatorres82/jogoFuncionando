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
        comandosMovimento.push_back(sf::Keyboard::A);
        comandosMovimento.push_back(sf::Keyboard::D);
        comandosMovimento.push_back(sf::Keyboard::Space);
        comandosMovimento.push_back(sf::Keyboard::Up);
        comandosMovimento.push_back(sf::Keyboard::Left);
        comandosMovimento.push_back(sf::Keyboard::Right);
        

        comandosFechamento.push_back(sf::Keyboard::Escape);
        comandosFechamento.push_back(sf::Keyboard::BackSpace);

    }

    Gerenciador_Inputs::~Gerenciador_Inputs() {
        comandosMovimento.clear();
        comandosFechamento.clear();
        
        list<Observadores::Observador*>::iterator it = observadoresVigiando.begin();
        while(it != observadoresVigiando.end())
        {
            observadoresVigiando.erase(it);
            it++;
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