#include "../../includes/Gerenciadores/Gerenciador_Estados.h"

using namespace Gerenciadores;

Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

Gerenciador_Estados::Gerenciador_Estados()
{
    estado_atual = nullptr;
}
Gerenciador_Estados::~Gerenciador_Estados()
{
    limpar();
    if(estado_atual != nullptr)
    {
        delete estado_atual;
    }
    delete instancia;
}

Gerenciador_Estados* Gerenciador_Estados::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new Gerenciador_Estados();
    }

    return instancia;
}

void Gerenciador_Estados::limpar()
{
    while (!estados.empty())
    {
        delete estados.begin()->second;
        estados.erase(estados.begin());
    }
    estados.clear();
}

void Gerenciador_Estados::criarEstados()
{
    try
    {
        Estados::Menus::Menu* menuPrin = new Estados::Menus::MenuPrincipal();
        adicionarEstado("MenuPrincipal", menuPrin);
        if (menuPrin == nullptr)
        {
            throw "Erro ao criar estado MenuPrincipal";
        }
        
    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
        return;
    } 
    
    try
    {
        Estados::Jogando* jogando = new Estados::Jogando("Jogando");
        adicionarEstado("Jogando", jogando);
        if(jogando == nullptr)
        {
            throw "Erro ao criar estado Jogando";
        }

    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
        return;
    }

    try
    {
        {
            Estados::Menus::Menu* menuSelec = new Estados::Menus::MenuSelecao();
            adicionarEstado("MenuSelecao", menuSelec);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Estados::Menus::Menu* menuPausa = new Estados::Menus::MenuPausa();
        adicionarEstado("MenuPausa", menuPausa);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    mudaEstado("MenuPrincipal");
}

void Gerenciador_Estados::adicionarEstado(const std::string &id, Estados::Estado *estado)
{
    estados.insert(std::pair<std::string, Estados::Estado*>(id, estado));
}

void Gerenciador_Estados::removerEstado(const std::string& id)
{
    estados.erase(id);
}

Estados::Estado* Gerenciador_Estados::getEstado(const std::string& id)
{
    return estados[id];
}

void Gerenciador_Estados::mudaEstado(const std::string& id)
{
    if (estado_atual != nullptr)
    {
        if (estado_atual->getId() == id)
        {
            return;
        }
    }
    if(estados[id] == nullptr)
    {
        std::cout << "Erro ao mudar de estado" << std::endl;
        return;
    }
    estado_atual = estados[id];
    cout << "Mudou de estado e agora eh: " << estado_atual->getId() << endl;    
}

void Gerenciador_Estados::executar()
{
    if (estado_atual != nullptr)
    {
        estado_atual->exec(); 
    }

    else
    {
        std::cerr << "Erro ao executar estado" << std::endl;
    }	
}

void Gerenciador_Estados::vaiSerCoop()
{
    
    Estados::Jogando* jogando = dynamic_cast<Estados::Jogando*>(getEstado("Jogando"));
    Estados::Menus::MenuSelecao* menuSel = dynamic_cast<Estados::Menus::MenuSelecao*>(getEstado("MenuSelecao"));
    Estados::Menus::MenuPausa* menuPausa = dynamic_cast<Estados::Menus::MenuPausa*>(getEstado("MenuPausa"));
    
    if(jogando == nullptr || menuSel == nullptr)
    {
        std::cerr << "Erro ao mudar de estado" << std::endl;
        return;
    }
    if(menuSel->HaDoisJogadores())
    {
        jogando->criaFase(true);
    }
    else 
        jogando->criaFase(false);
    
    menuPausa->setFase(jogando->getFase());
}

