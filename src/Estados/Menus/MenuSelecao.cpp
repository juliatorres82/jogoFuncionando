#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"
namespace Estados
{
    namespace Menus
    {
        MenuSelecao::MenuSelecao():
        Menu("MenuSelecao"), doisJogadores(false)
        {
            adicionarBotao("Fase 1: 1 Jogador", sf::Vector2f(200, 50), sf::Vector2f(300, 200));
            adicionarBotao("Fase 1: 2 Jogadores", sf::Vector2f(200, 50), sf::Vector2f(300, 300));
            adicionarBotao("Fase 2: 1 jogador", sf::Vector2f(200, 50), sf::Vector2f(300, 400));
            adicionarBotao("Fase 2: 2 Jogadores", sf::Vector2f(200, 50), sf::Vector2f(300, 500));
            adicionarBotao("Voltar", sf::Vector2f(200, 50), sf::Vector2f(300, 600));
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
                    posAtual = botoes.begin();
                    (*posAtual)->setSelecionado(true);
                    (*it)->setSelecionado(false);
                    mudaClicaBotao(*it);
                    if((*it)->getTexto() == "Fase1: 1 Jogador" || (*it)->getTexto() == "Fase2: 1 Jogador")
                    {
                        doisJogadores = false;
                        if((*it)->getTexto() == "Fase1: 1 Jogador")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((*it)->getTexto() == "Fase2: 1 Jogador")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    
                    else if((*it)->getTexto() == "Fase1: 2 Jogadores" || (*it)->getTexto() == "Fase2: 2 Jogadores")
                    {
                        doisJogadores = true;
                        if((*it)->getTexto() == "Fase1: 2 Jogadores")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((*it)->getTexto() == "Fase2: 2 Jogadores")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    else if((*it)->getTexto() == "Voltar")
                    {
                        gerenciador_estados->mudaEstado("MenuPrincipal");
                        return;
                    }
                    gerenciador_estados->vaiSerCoop(doisJogadores);
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
            executar();
            desenhar();
        }
    }


}