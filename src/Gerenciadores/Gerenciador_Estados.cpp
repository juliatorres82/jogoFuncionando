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
    }
    estados.clear();
}
void Gerenciador_Estados::criarEstados()
{
    Estados::Menu* menu = new Estados::Menu("Menu");
    //Estados::Jogando* jogando = new Estados::Jogando();
    adicionarEstado("Menu", static_cast<Estados::Estado*>(menu));
    mudaEstado("Menu");
}
void Gerenciador_Estados::adicionarEstado(const std::string &id, Estados::Estado *estado, const bool &substituir)
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
    estado_atual = estados[id];
}

void Gerenciador_Estados::executar()
{
    if (estado_atual != nullptr)
    {
        estado_atual->exec();
    }
}

