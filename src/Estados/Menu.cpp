#include "../../includes/Observadores/ObservadorMenu.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
using namespace Observadores;

Estados::Menu::Menu():
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

    adicionarBotao("Jogar", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
    adicionarBotao( "Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));
    it = botoes.begin();
    (*it)->setSelecionado(true);
}


Estados::Menu::Menu(const std::string &iD):
Estado(iD), Ente(menu)
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

    adicionarBotao("Jogar", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
    adicionarBotao( "Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));
    it = botoes.begin();
    (*it)->setSelecionado(true);
}
Estados::Menu::~Menu()
{
    if(observadorMenu != nullptr)
    {
        delete observadorMenu;
    }
    observadorMenu = nullptr;
    limpar();
}

void Estados::Menu::setFundo(const string &caminho)
{
    textura_fundo.loadFromFile(caminho);
    fundo.setSize(sf::Vector2f(pGG->getJanela()->getSize().x, pGG->getJanela()->getSize().y));
    fundo.setTexture(&textura_fundo);
}

void Estados::Menu::setTitulo(const string &texto)
{
    titulo.setString(texto);
}

void Estados::Menu::setPosTitulo(const sf::Vector2f &pos)
{
    titulo.setPosition(pos);
}

void Estados::Menu::setCorTitulo(const sf::Color &cor)
{
    titulo.setFillColor(cor);
}

void Estados::Menu::setTamTitulo(const unsigned int &tam)
{
    titulo.setCharacterSize(tam);
}

void Estados::Menu::limpar()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        delete *it;
    }
    botoes.clear();
}

void Estados::Menu::adicionarBotao(const string &texto, const sf::Vector2f &tam, const sf::Vector2f &pos)
{
    Botao *botao = new Botao(tam, pos, texto);
    if(botao == nullptr)
    {
        std::cout << "Erro ao criar botao" << std::endl;
    }
    botao->setFonte("C:/Users/vinic/Desktop/projetos/joguinhoNoVSCode/mainJogoFuncionando/jogoFuncionando/fontes/NewAmsterdam-Regular.ttf");
    botoes.push_back(botao);
}

void Estados::Menu::atualizar()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        (*it)->atualizar();
    }
}

void Estados::Menu::exec()
{
    desenhar();
    executar();
    atualizar();
}

void Estados::Menu::desenhar()
{
    pGG->desenhar(fundo);
    pGG->desenhar(titulo);
    
        for(it = botoes.begin(); it != botoes.end(); it++)
    {
        (*it)->desenhar();
    }
}

void Estados::Menu::executar()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        if((*it)->getClicado())
        {
            if((*it)->getTexto() == "Jogar")
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

void Estados::Menu::moverCima()
{
    if(it != botoes.begin())
    {
        (*it)->setSelecionado(false);
        it--;
        (*it)->setSelecionado(true);
    }
}

void Estados::Menu::moverBaixo()
{
    if(it != botoes.end())
    {
        (*it)->setSelecionado(false);
        it++;
        (*it)->setSelecionado(true);
    }
}

void Estados::Menu::selecionar()
{
    (*it)->executar();
}