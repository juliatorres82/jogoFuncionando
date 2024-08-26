#include "../../includes/Gerenciadores/Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Estados::instancia = nullptr;

Gerenciadores::Gerenciador_Estados::Gerenciador_Estados()
{
    estado_atual = nullptr;
}
Gerenciadores::Gerenciador_Estados::~Gerenciador_Estados()
{
    limpar();
    if(estado_atual != nullptr)
    {
        delete estado_atual;
    }
    delete instancia;
}

Gerenciadores::Gerenciador_Estados* Gerenciadores::Gerenciador_Estados::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new Gerenciador_Estados();
    }

    return instancia;
}

void Gerenciadores::Gerenciador_Estados::limpar()
{
    while (!estados.empty())
    {
        delete estados.begin()->second;
    }
    estados.clear();
}
void Gerenciadores::Gerenciador_Estados::criarEstados()
{
    adicionarEstado("Menu", new Menu());
    adicionarEstado("Jogando", new Jogando());
}
void Gerenciadores::Gerenciador_Estados::adicionarEstado(const std::string &id, Estados::Estado *estado, const bool &substituir)
{
    estados.insert(std::pair<std::string, Estados::Estado*>(id, estado));
}

void Gerenciadores::Gerenciador_Estados::removerEstado(const std::string& id)
{
    estados.erase(id);
}

Estados::Estado* Gerenciadores::Gerenciador_Estados::getEstado(const std::string& id)
{
    return estados[id];
}

void Gerenciadores::Gerenciador_Estados::mudaEstado(const std::string& id)
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

void Gerenciadores::Gerenciador_Estados::executar()
{
    if (estado_atual != nullptr)
    {
        estado_atual->exec();
    }
}

