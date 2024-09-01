#include "../../includes/Gerenciadores/Gerenciador_Estados.h"

Estados::Estado::Estado()
{
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
}

Estados::Estado::Estado(const std::string& id)
{
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
    setId(id);
}
Estados::Estado::~Estado()
{
    if(gerenciador_estados)
    {
        delete gerenciador_estados;
    }
    gerenciador_estados = nullptr;
}

void Estados::Estado::setId(const std::string& id)
{
    this->idEst = id;
}

const std::string &Estados::Estado::getId() const
{
    return idEst;
}

void Estados::Estado::mudaEstadoAtivo(const std::string& outroEstado)
{
    gerenciador_estados->mudaEstado(outroEstado);
}