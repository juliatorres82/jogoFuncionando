#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
using namespace Estados;

Estado::Estado()
{
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
}

Estado::~Estado()
{
    if(gerenciador_estados)
    {
        delete gerenciador_estados;
    }
    gerenciador_estados = nullptr;
}

void Estado::setId(const std::string& id)
{
    this->idEst = id;
}

const std::string &Estados::Estado::getId() const
{
    return idEst;
}
