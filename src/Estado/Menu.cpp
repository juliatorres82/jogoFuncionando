#include "Menu.h"

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
