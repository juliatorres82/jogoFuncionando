#include "../../includes/Estados/Jogando.h"

Estados::Jogando::Jogando(const std::string &id)
{
    setId(id);
    fase = nullptr;
    printf("constr. jogando funcionando\n"); 
}

Estados::Jogando::~Jogando()
{
    /*if(fase)
    {
        delete fase;
    }
    fase = nullptr;*/
}

void Estados::Jogando::criaFase(bool coop)
{
    fase = new Fases::Fase1(coop); 
    fase->constroiFase();
    cout <<"construiu fase" <<endl;
}

void Estados::Jogando::exec()
{
    printf("estado jogando executado\n"); 

    if(fase){
        fase->executar();
    }
    else
    {
        std::cerr << "Erro ao executar fase->exec"<< std::endl;
    }cd 
    try{
        fase->executar();
    }
    catch(const std::bad_alloc& e){
        std::cerr << "Erro ao executar fase->exe"<< e.what() << std::endl;
    }
}

void Estados::Jogando::atualizar()
{
    fase->atualizar();
}