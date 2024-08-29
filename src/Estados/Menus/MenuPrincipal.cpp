#include "../../../includes/Estados/Menus/MenuPrincipal.h"
#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal() : doisJogadores(false) {
            try
            {
                
            }
            catch (const std::bad_alloc& e)
            {
                std::cerr << "Erro ao criar MenuPrincipal: " << e.what() << std::endl;
                return;
            }
        }

        MenuPrincipal::~MenuPrincipal() {}

        const bool MenuPrincipal:: HaDoisJogadores() {
            return doisJogadores;
        }

        void MenuPrincipal:: setDoisJogadores(){
            doisJogadores = true;
        }

        void MenuPrincipal::exec() 
        {
            executar();
            desenhar();
        }
        void Menus::MenuPrincipal::desenhar()
        {
            pGG->desenhar(fundo);
            pGG->desenhar(titulo);

            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                (*it)->desenhar();
            }
        }

        void Menus::MenuPrincipal::executar()
        {
            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                if((*it)->getClicado())
                {
                    if((*it)->getTexto() == "Novo Jogo")
                    {
                        gerenciador_estados->mudaEstado("Jogando");
                    }
                    
                    else if((*it)->getTexto() == "Sair")
                    {
                        pGG->getJanela()->close();
                    }
                }
            }
        }
    }
}



