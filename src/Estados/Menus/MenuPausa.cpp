#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"

namespace Estados
{
    namespace Menus
    {
        MenuPausa::MenuPausa(): Menu("MenuPausa")
        {
            fundo.setSize(sf::Vector2f(pGG->getTamx()/5, pGG->getTamy()));
            fundo.setFillColor(sf::Color::White);
            fundo.setPosition(pGG->getTamx()/2 - fundo.getSize().x/2, 0);
            adicionarBotao("Retomar",sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/4));
            adicionarBotao("Salvar", sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/4 + espacoBotao));
            adicionarBotao( "Sair", sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/4 + 2*espacoBotao));
            inicializar();
        }

        MenuPausa::~MenuPausa()
        {
            limpar();
        }

        void MenuPausa::setFase(Fases::Fase* f)
        {
            fase = f;
        }

        void MenuPausa::exec()
        {
            if(!observadorMenu->getEstadoAtivo())
            {
                observadorMenu->mudaEstadoAtivo();
            }
            executar();
            desenhar();
        }
        
        void MenuPausa::executar()
        {
            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                if((*it)->getClicado())
                {
                    mudaClicaBotao(*it);
                    (*it)->setSelecionado(false);

                    if((*it)->getTexto() == "Sair" || (*it)->getTexto() == "Retomar")
                    {
                        if((*it)->getTexto() == "Sair")
                        {
                            gerenciador_estados->mudaEstado("MenuPrincipal");
                        }
                        else
                        {
                            gerenciador_estados->mudaEstado("Jogando");
                        }

                        posAtual = botoes.begin();
                        (*posAtual)->setSelecionado(true);
                        observadorMenu->mudaEstadoAtivo();
                        atualizar();
                    }
                    
                    else if((*it)->getTexto() == "Salvar")
                    {
                        //falta implemetar
                    }
                    
                }
            }
        }
        void MenuPausa::desenhar()
        {
            fase->desenhar();
            pGG->desenhar(fundo);

            for(it = botoes.begin(); it != botoes.end(); it++)
            {
                (*it)->desenhar();
            }
        }
        

    }
    
}
