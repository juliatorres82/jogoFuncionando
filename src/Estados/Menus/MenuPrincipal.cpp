#include "../../../includes/Estados/Menus/MenuPrincipal.h"
#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"

namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal() : Menu("MenuPrincipal") {
            
                setFundo("../imagens/BG-MainMenu.jpeg");
                titulo.setFont(fonte);
                setTamTitulo(200);
                setCorTitulo(sf::Color::Black);
                setTitulo("Titulo");
                setPosTitulo(sf::Vector2f(pGG->getTamx()/2, 0));
                adicionarBotao("Novo Jogo", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
                adicionarBotao( "Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));
                inicializar();
        }

        MenuPrincipal::~MenuPrincipal() {}

        void MenuPrincipal::setTitulo(const string &texto)
        {
            titulo.setString(texto);
        }

        void MenuPrincipal::setPosTitulo(const sf::Vector2f &pos)
        {
            titulo.setOrigin(titulo.getGlobalBounds().width/2, titulo.getGlobalBounds().height/2);
            titulo.setPosition(pos);
        }

        void MenuPrincipal::setCorTitulo(const sf::Color &cor)
        {
            titulo.setFillColor(cor);
        }

        void MenuPrincipal::setTamTitulo(const unsigned int &tam)
        {
            titulo.setCharacterSize(tam);
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
                        observadorMenu->mudaEstadoAtivo();
                        //gerenciador_estados->mudaEstado("MenuSelecao");
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



