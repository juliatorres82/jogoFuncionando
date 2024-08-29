#include "../../includes/Observadores/ObservadorMenu.h"
#include "../../includes/Gerenciadores/Gerenciador_Estados.h"

Estados::Menu::Menu()
{
}

Estados::Menu::Menu(const std::string &id)
{
    this->idEst = id;
    pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
    fonte.loadFromFile("C:/Users/vinic/Desktop/projetos/joguinhoNoVSCode/mainJogoFuncionando/jogoFuncionando/fontes/04B_19__.TTF");
    titulo.setFont(fonte);
    titulo.setCharacterSize(50);
    titulo.setFillColor(sf::Color::White);
    titulo.setString("Titulo");
    titulo.setPosition(pGG->getTamx()/2, 0);
}

Estados::Menu::~Menu()
{
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
    exec();
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