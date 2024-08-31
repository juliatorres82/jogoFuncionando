#include "../../../includes/Gerenciadores/Gerenciador_Estados.h"

using namespace Observadores;
namespace Estados
{
    namespace Menus
    {
        Menu::Menu():
        Estado("Menu"), Ente(menu)
        {
            pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
            fonte.loadFromFile("../fontes/NewAmsterdam-Regular.ttf");
            
            limpar();
            
            // Verifique se o ponteiro this é válido
            if (this == nullptr) {
                std::cerr << "Erro: this é nullptr no construtor de Menu" << std::endl;
                return;
            }

                observadorMenu = new ObservadorMenu(this);
                if (observadorMenu == nullptr) {
                    std::cerr << "Erro: falha ao alocar memória para ObservadorMenu" << std::endl;
                    return;
                }
        }


        Menu::Menu(const std::string &iD):
        Estado(iD), Ente(menu)
        {
            try
            {
                pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
                fonte.loadFromFile("../fontes/NewAmsterdam-Regular.ttf");
                observadorMenu = new ObservadorMenu(this);
            }

            catch(const std::bad_alloc& e)
            {
                std::cerr << "Erro ao criar Menu: " << e.what() << std::endl;
                return;
            }
            limpar();
            
        }
        
        Menu::~Menu()
        {
            if(observadorMenu != nullptr)
            {
                delete observadorMenu;
            }
            observadorMenu = nullptr;
            limpar();
        }

        void Menu::setFundo(const string &caminho)
        {
            textura_fundo.loadFromFile(caminho);
            fundo.setSize(sf::Vector2f(pGG->getJanela()->getSize().x, pGG->getJanela()->getSize().y));
            fundo.setPosition(pGG->getJanela()->getPosition().x, pGG->getJanela()->getPosition().y);
            fundo.setFillColor(sf::Color::White);
            fundo.setTexture(&textura_fundo);
        }

                void Menu::inicializar()
        {
            try
            {
                it = posAtual = botoes.begin();
                (*posAtual)->setSelecionado(true);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Erro ao inicializar Menu: " << e.what() << std::endl;
                return;
            }
            
        }

        void Menu::limpar()
        {
        for(it = botoes.begin(); it != botoes.end(); it++)
        {
            delete *it;
        }
            botoes.clear();
        }

        void Estados::Menus::Menu::adicionarBotao(const string &texto, const sf::Vector2f &tam, const sf::Vector2f &pos)
        {
            Botao *botao = new Botao(tam, pos, texto);
            if(botao == nullptr)
            {
                std::cout << "Erro ao criar botao" << std::endl;
            }
            
            botoes.push_back(botao);
        }

            void Estados::Menus::Menu::atualizar()
            {
                for(it = botoes.begin(); it != botoes.end(); it++)
                {
                    (*it)->atualizar();
                }
            }

            void Estados::Menus::Menu::moverCima()
            {
                Botao* botao = (*posAtual);
                botao->setSelecionado(false);

                if (posAtual == botoes.begin()) {
                    posAtual = botoes.end();
                }
                posAtual--;

                botao = (*posAtual);
                botao->setSelecionado(true);

                atualizar();
            }

            void Estados::Menus::Menu::moverBaixo()
            {
                (*posAtual)->setSelecionado(false);
                posAtual++;
                if(posAtual == botoes.end())
                {   
                    posAtual = botoes.begin();
                }
                (*posAtual)->setSelecionado(true);
                
                atualizar();
            }

            void Estados::Menus::Menu::selecionar()
            {
                (*posAtual)->executar();
                atualizar();
            }

            void Estados::Menus::Menu::mudaClicaBotao(Botao* it)
            {
                it->setClicado(false);
            }
    }
}

