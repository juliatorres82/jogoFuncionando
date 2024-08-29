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
        Estados::Menu* menu = new Estados::MenuPrincipal();
        adicionarEstado("Menu", menu);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Erro ao criar estado Menu: " << e.what() << std::endl;
        return;
    }

    try
    {
        Estados::Jogando* jogando = new Estados::Jogando("Jogando");
        adicionarEstado("Jogando", jogando);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Erro ao criar estado Jogando: " << e.what() << std::endl;
        return;
    }

    mudaEstado("Menu");
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

