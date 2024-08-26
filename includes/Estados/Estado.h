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
            virtual ~Estado();
            void setIdEst(const std::string& id);
            const std::string& getIdEst() const;
            virtual void atualizar() = 0;
            virtual void exec() = 0;
            virtual void iniciar() = 0;
    };
}
