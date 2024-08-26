#include "../../includes/Estados/Menu.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"
Menu::Menu()
{
}

Menu::Menu(const std::string &id)
{
    this->idEst = id;
    pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
    fonte.loadFromFile("resources/fonts/arial.ttf");
    titulo.setFont(fonte);
    titulo.setCharacterSize(50);
    titulo.setFillColor(sf::Color::White);
    titulo.setString("Titulo");
    titulo.setPosition(pGG->getTamx()/2, 0);
    selecionado = false;
}

Menu::~Menu()
{
    limpar();
}

void Menu::setFundo(const string &caminho)
{
    textura_fundo.loadFromFile(caminho);
    fundo.setSize(sf::Vector2f(pGG->getJanela()->getSize().x, pGG->getJanela()->getSize().y));
    fundo.setTexture(&textura_fundo);
}

void Menu::limpar()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        delete *it;
    }
    botoes.clear();
}
void Menu::adicionarBotao(const string &texto, const sf::Vector2f &tam, const sf::Vector2f &pos)
{
    Botao *botao = new Botao(tam, pos, texto);
    botoes.push_back(botao);
}

void Menu::atualizar()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        (*it)->atualizar();
    }
}

void Menu::exec()
{
    for(it = botoes.begin(); it != botoes.end(); it++)
    {
        (*it)->desenhar();
    }
}

void Menu::desenhar()
{
    pGG->desenhar(fundo);
    pGG->desenhar(titulo);
    exec();
}

void Menu::executar()
{
    desenhar();
    exec();
    atualizar();
}

void Menu::iniciar()
{
    setFundo("resources/images/fundo.png");
    setTitulo("Menu");
    setPosTitulo(sf::Vector2f(pGG->getTamx()/2, 0));
    setCorTitulo(sf::Color::White);
    setTamTitulo(50);
    adicionarBotao("Jogar", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2));
    adicionarBotao("Sair", sf::Vector2f(200, 50), sf::Vector2f(pGG->getTamx()/2, pGG->getTamy()/2 + 100));

    gerenciador_estados->adicionarEstado(this->getIdEst(), this);
}
