#include "../../includes/Observadores/ObservadorMenu.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
using namespace Observadores;
namespace Menus
{

    Estados::Menus::Menu::Menu():
    Estado("Menu"), Ente(menu)
    {
        pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
        fonte.loadFromFile("C:/Users/vinic/Desktop/projetos/JogoSimas/joguinho_lindo/joguinho_lindo/NewAmsterdam-Regular.ttf");
        titulo.setFont(fonte);
        limpar();
        titulo.setCharacterSize(50);
        titulo.setFillColor(sf::Color::White);
        titulo.setString("Titulo");
        titulo.setPosition(pGG->getTamx()/2, 0);
        
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

        adicionarBotao("Iniciar", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
        adicionarBotao( "Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));
        it = botoes.begin();
        (*it)->setSelecionado(true);
    }


    Estados::Menus::Menu::Menu(const std::string &iD):
    Estado(iD), Ente(menu)
    {
        pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
        fonte.loadFromFile("C:/Users/vinic/Desktop/projetos/JogoSimas/joguinho_lindo/joguinho_lindo/NewAmsterdam-Regular.ttf");
        titulo.setFont(fonte);
        setFundo("C:/Users/vinic/Desktop/projetos/JogoSimas/joguinho_lindo/joguinho_lindo/imagens/BG-MainMenu.jpeg");

        limpar();
        titulo.setCharacterSize(200);
        titulo.setFillColor(sf::Color::Black);
        titulo.setString("Titulo");
        titulo.setPosition(pGG->getTamx()/2, 0.f);
        
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

        adicionarBotao("Jogar", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
        adicionarBotao( "Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));
        it = posAtual = botoes.begin();
        (*posAtual)->setSelecionado(true);
    }
    Estados::Menus::Menu::~Menu()
    {
        if(observadorMenu != nullptr)
        {
            delete observadorMenu;
        }
        observadorMenu = nullptr;
        limpar();
    }

    void Estados::Menus::Menu::setFundo(const string &caminho)
    {
        //textura_fundo.loadFromFile(caminho);
        fundo.setSize(sf::Vector2f(pGG->getJanela()->getSize().x, pGG->getJanela()->getSize().y));
        fundo.setPosition(pGG->getJanela()->getPosition().x, pGG->getJanela()->getPosition().y);
        fundo.setFillColor(sf::Color::White);
        //fundo.setTexture(&textura_fundo);
    }

    void Estados::Menus::Menu::setTitulo(const string &texto)
    {
        titulo.setString(texto);
    }

    void Estados::Menus::Menu::setPosTitulo(const sf::Vector2f &pos)
    {
        titulo.setPosition(pos);
    }

    void Estados::Menus::Menu::setCorTitulo(const sf::Color &cor)
    {
        titulo.setFillColor(cor);
    }

    void Estados::Menus::Menu::setTamTitulo(const unsigned int &tam)
    {
        titulo.setCharacterSize(tam);
    }

    void Estados::Menus::Menu::limpar()
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
        botao->setFonte("C:/Users/vinic/Desktop/projetos/joguinhoNoVSCode/mainJogoFuncionando/jogoFuncionando/fontes/NewAmsterdam-Regular.ttf");
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
}