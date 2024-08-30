#include "../../../includes/Estados/Menus/MenuSelecao.h"

namespace Estados
{
    namespace Menus
    {
        MenuSelecao::MenuSelecao():
        Menu("MenuSelecao"), doisJogadores(false)
        {
            adicionarBotao("Fase 1: Um Jogador", sf::Vector2f(200, 50), sf::Vector2f(300, 200));
            adicionarBotao("Fase 1: Dois Jogadores", sf::Vector2f(200, 50), sf::Vector2f(300, 300));
            adicionarBotao("Fase 2: Um jogador", sf::Vector2f(200, 50), sf::Vector2f(300, 400));
            adicionarBotao("Fase 2: Dois Jogadores", sf::Vector2f(200, 50), sf::Vector2f(300, 500));
            adicionarBotao("Voltar", sf::Vector2f(200, 50), sf::Vector2f(300, 400));
            inicializar();
        }

        MenuSelecao::~MenuSelecao()
        {
            limpar();
        }

        void MenuSelecao::desenhar()
        {
            pGG->desenhar(fundo);
            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                (*it)->desenhar();
            }
        }

        void MenuSelecao::executar()
        {
            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                if((*it)->getClicado())
                {
                    if((*it)->getTexto() == "Fase1")
                    {
                        observadorMenu->mudaEstadoAtivo();
                        //gerenciador_estados->mudaEstado("MenuSelecao");
                    }
                    
                    else if((*it)->getTexto() == "Voltar")
                    {
                        pGG->getJanela()->close();
                    }
                }
            }
        }

        void MenuSelecao::setDoisJogadores()
        {
            doisJogadores = true;
        }

        const bool MenuSelecao::HaDoisJogadores()
        {
            return doisJogadores;
        }
    }
}