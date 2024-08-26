#pragma once
#include "Estado.h"
#include "../Botao.h"
#include <list>
class Menu: public Estados::Estado, public Ente
{
    private:
        list<Botao*> botoes;
        list<Botao*>::iterator it;
        sf::RectangleShape fundo;
        sf::Texture textura_fundo;
        sf::Text titulo;
        sf::Font fonte;
        bool selecionado;
    public:
        Menu();
        Menu(const std::string& id);
        void limpar();
        virtual ~Menu();
        void setFundo(const string& caminho);
        void setTitulo(const string& texto);
        void setPosTitulo(const sf::Vector2f& pos);
        void setCorTitulo(const sf::Color& cor);
        void setTamTitulo(const unsigned int& tam);
        void adicionarBotao(const string& texto, const sf::Vector2f& tam, const sf::Vector2f& pos);
        void atualizar();
        virtual void exec();
        virtual void desenhar();
        void executar();
};