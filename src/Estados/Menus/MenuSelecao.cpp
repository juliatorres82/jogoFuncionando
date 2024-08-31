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
            adicionarBotao("Fase 2: 1 Jogador", sf::Vector2f(200, 50), sf::Vector2f(300, 400));
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
                    Botao* bot = *it;
                    atualizar();
                    observadorMenu->mudaEstadoAtivo();

                    if((bot)->getTexto() == "Fase 1: 1 Jogador" || (bot)->getTexto() == "Fase 2: 1 Jogador")
                    {
                        doisJogadores = false;
                        if((bot)->getTexto() == "Fase 1: 1 Jogador")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((bot)->getTexto() == "Fase 2: 1 Jogador")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    
                    else if((bot)->getTexto() == "Fase 1: 2 Jogadores" || (bot)->getTexto() == "Fase 2: 2 Jogadores")
                    {
                        doisJogadores = true;
                        if((bot)->getTexto() == "Fase 1: 2 Jogadores")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                        else if((bot)->getTexto() == "Fase 2: 2 Jogadores")
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }
                    }
                    else if((bot)->getTexto() == "Voltar")
                    {
                        gerenciador_estados->mudaEstado("MenuPrincipal");
                        return;
                    }
                    cout << observadorMenu->getEstadoAtivo() << endl;
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