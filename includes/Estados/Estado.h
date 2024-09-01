#pragma once
#include <string>
using namespace std;

namespace Gerenciadores
{
    class Gerenciador_Estados;
}

namespace Estados
{
    class Estado
    {
        protected:
            Gerenciadores::Gerenciador_Estados* gerenciador_estados;
            std::string idEst;

        public:
            Estado();
            Estado(const std::string& id);
            virtual ~Estado();
            void setId(const std::string& id);
            const std::string& getId() const;
            void mudaEstadoAtivo(const std::string& outroEstado);
            virtual void atualizar() = 0;
            virtual void exec() = 0;
    };
}
