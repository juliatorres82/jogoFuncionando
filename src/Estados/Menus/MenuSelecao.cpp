#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"
namespace Estados
{
    namespace Menus
    {
        MenuSelecao::MenuSelecao():
        Menu("MenuSelecao"), doisJogadores(false)
        {
            adicionarBotao("Fase 1: Solo", sf::Vector2f(pGG->getTamx()/2, 100));
            adicionarBotao("Fase 1: Coop", sf::Vector2f(pGG->getTamx()/2, 100 + espacoBotao));
            adicionarBotao("Fase 2: Solo", sf::Vector2f(pGG->getTamx()/2, 100 + 2*espacoBotao));
            adicionarBotao("Fase 2: Coop", sf::Vector2f(pGG->getTamx()/2, 100 + 3*espacoBotao));
            adicionarBotao("Voltar", sf::Vector2f(pGG->getTamx()/2, 100 + 4*espacoBotao));
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
                    (*it)->setSelecionado(false);
                    mudaClicaBotao(*it);
                    Botao* bot = *it;
                    posAtual = botoes.begin();
                    (*posAtual)->setSelecionado(true);
                    atualizar();
                    observadorMenu->mudaEstadoAtivo();

                    if((bot)->getTexto() == "Fase 1: Solo" || (bot)->getTexto() == "Fase 2: Solo")
                    {
                        doisJogadores = false;
                        if((bot)->getTexto() == "Fase 1: Solo")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((bot)->getTexto() == "Fase 2: Solo")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    
                    else if((bot)->getTexto() == "Fase 1: Coop" || (bot)->getTexto() == "Fase 2: Coop")
                    {
                        doisJogadores = true;
                        if((bot)->getTexto() == "Fase 1: Coop")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((bot)->getTexto() == "Fase 2: Coop")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    else if((bot)->getTexto() == "Voltar")
                    {
                        gerenciador_estados->mudaEstado("MenuPrincipal");
                        return;
                    }
                    gerenciador_estados->vaiSerCoop();
                }
            }
        }

        const bool MenuSelecao::HaDoisJogadores()
        {
            return doisJogadores;
        }

        void MenuSelecao::exec()
        {
            if(!observadorMenu->getEstadoAtivo())
            {
                observadorMenu->mudaEstadoAtivo();
            }
            desenhar();
            executar();
        }
    }


}