#pragma once
#include "../Estados/Menus/MenuPrincipal.h"
#include "../Estados/Menus/MenuPausa.h"
#include "../Estados/Menus/MenuSelecao.h"
#include "../Estados/Jogando.h"
#include <map>
#include <string>
using std::map;

namespace Gerenciadores 
{
    class Gerenciador_Estados
    {
        private:
            map<std::string, Estados::Estado*> estados;
            Estados::Estado* estado_atual;
            static Gerenciador_Estados* instancia;
            Gerenciador_Estados();

        public:
            ~Gerenciador_Estados();
            static Gerenciador_Estados* getInstancia();
            void limpar();
            void criarEstados();
            void adicionarEstado(const std::string& id, Estados::Estado* estado);
            void removerEstado(const std::string& id);
            Estados::Estado* getEstado(const std::string& id);
            void mudaEstado(const std::string& id);
            void executar();
            void vaiSerCoop(bool coop);
    };
}