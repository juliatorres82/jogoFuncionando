#pragma once
#include "../Estado.h"
#include "../../Botao.h"
#include <list>

namespace Observadores
{
    class ObservadorMenu;
}

namespace Gerenciadores
{
    class Gerenciador_Estados;
}
namespace Estados
{
    namespace Menus
    {
        class Menu: public Estado, public Ente
        {
            protected:
                list<Botao*> botoes;
                Observadores::ObservadorMenu* observadorMenu;
                list<Botao*>::iterator it;
                list<Botao*>::iterator posAtual;
                sf::RectangleShape fundo;
                sf::Texture textura_fundo;
                sf::Text titulo;
                sf::Font fonte;
                
            public:
                Menu();
                Menu(const std::string& iD);
                void limpar();
                virtual ~Menu();
                void setFundo(const string& caminho);
                void setTitulo(const string& texto);
                void setPosTitulo(const sf::Vector2f& pos);
                void setCorTitulo(const sf::Color& cor);
                void setTamTitulo(const unsigned int& tam);
                void adicionarBotao(const string& texto, const sf::Vector2f& tam, const sf::Vector2f& pos);
                void atualizar();
                void exec() = 0;
                virtual void desenhar() = 0 ;
                virtual void executar() = 0;
                void moverCima();
                void moverBaixo();
                void selecionar();
     };
    }
    
}