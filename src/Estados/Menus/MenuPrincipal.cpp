#include "../../../includes/Estados/Menus/MenuPrincipal.h"
#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"
#define tamTitulo 100
namespace Estados
{
    namespace Menus
    {
        MenuPrincipal::MenuPrincipal() : Menu("MenuPrincipal") {
            
                setFundo("../imagens/BG-MainMenu.jpeg");
                titulo.setFont(fonte);
                setTamTitulo(tamTitulo);
                setCorTitulo(sf::Color::Black);
                setTitulo("Titulo");
                setPosTitulo(sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/4));
                adicionarBotao("Novo Jogo",sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
                adicionarBotao( "Sair", sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + espacoBotao));
                inicializar();
        }

        MenuPrincipal::~MenuPrincipal() {
            limpar();
        }

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
            if(!observadorMenu->getEstadoAtivo())
            {
                cout << "entrou aqui" << endl;
                observadorMenu->mudaEstadoAtivo();
            }
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
                    mudaClicaBotao(*it);
                    (*it)->setSelecionado(false);

                    if((*it)->getTexto() == "Novo Jogo")
                    {
                        posAtual = botoes.begin();
                        (*posAtual)->setSelecionado(true);
                        observadorMenu->mudaEstadoAtivo();
                        atualizar();
                        gerenciador_estados->mudaEstado("MenuSelecao");
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



