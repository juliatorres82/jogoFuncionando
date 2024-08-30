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
    setTam(tam);
    setPos(pos);
    setCorRet(sf::Color::White);

   // fonte.loadFromFile("C:/Users/vinic/Desktop/projetos/JogoSimas/joguinho_lindo/joguinho_lindo/NewAmsterdam-Regular.ttf");
   sf::Font font;
    if (!font.loadFromFile("../fontes/NewAmsterdam-Regular.ttf")) {
    std::cerr << "Erro ao carregar a fonte" << std::endl;
    }
    //setFonte("NewAmsterdam-Regular.ttf");
    setCorTexto(sf::Color::Black);
    this->texto.setFont(fonte);
    this->texto.setString(texto);
    this->texto.setPosition(pos.x + 10, pos.y + 10);

    selecionado = false;
    ativo = true;
    clicado = false;
}

void Botao::setPos(const sf::Vector2f &pos)
{
    ret.setPosition(pos);
    texto.setPosition(pos.x + 10, pos.y + 10);
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

void Botao::setFonte(const string &caminho)
{
    fonte.loadFromFile(caminho);
    this->texto.setFont(fonte);
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