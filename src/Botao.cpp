#include "../includes/Botao.h"

using namespace Gerenciadores;

Botao::Botao()
{
    id = botao;
    selecionado = false;
    ativo = true;
    clicado = false;
    pGG = Gerenciador_Grafico::getInstancia();
}

Botao::~Botao()
{

}

Botao::Botao(const sf::Vector2f &tam, const sf::Vector2f &pos, const string &texto)
{
    fonte.loadFromFile("../fontes/NewAmsterdam-Regular.ttf");
    this->texto.setFont(fonte);
    setTam(tam);
    setCorTexto(sf::Color::Black);
    setTexto(texto);
    setPos(pos);
    setCorRet(sf::Color::White);
  

    selecionado = false;
    ativo = true;
    clicado = false;
}

void Botao::setPos(const sf::Vector2f &pos)
{
    ret.setOrigin(ret.getGlobalBounds().width/2, ret.getGlobalBounds().height/2);
    texto.setOrigin(texto.getGlobalBounds().width/2, texto.getGlobalBounds().height/2);
    ret.setPosition(pos);
    texto.setPosition(pos.x, pos.y);
}

void Botao::setTam(const sf::Vector2f &tam)
{
    ret.setSize(tam);
    texto.setCharacterSize(tam.y - 20);
}

void Botao::setTexto(const string &texto)
{
    this->texto.setString(texto);
}

void Botao::setCorTexto(const sf::Color &cor)
{
    texto.setFillColor(cor);
}

void Botao::setCorRet(const sf::Color &cor)
{
    ret.setFillColor(cor);
}

void Botao::setSelecionado(const bool selec)
{
    selecionado = selec;
}

void Botao::setAtivo(const bool ativo)
{
    this->ativo = ativo;
}

void Botao::desenhar()
{
    pGG->desenhar(ret);
    pGG->desenhar(texto);
}

void Botao::atualizar()
{
    if (ativo)
    {
        if (selecionado)
        {
            ret.setFillColor(sf::Color::Blue);
        }
        else
        {
            ret.setFillColor(sf::Color::White);
        }
    }
    else
    {
        ret.setFillColor(sf::Color::Black);
    }
}
void Botao::executar()
{
    if (ativo && selecionado)
    {
        clicado = true;
    }
}

bool Botao::getClicado()
{
    return clicado;
}

const string Botao::getTexto() const
{
    return texto.getString();
}

void Botao::setClicado(bool clicado)
{
    this->clicado = clicado;
}