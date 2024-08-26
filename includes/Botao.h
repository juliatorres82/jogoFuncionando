#include "Ente.h"

class Botao: public Ente
{
    private:
        sf::RectangleShape ret;
        sf::Text texto;
        sf::Font fonte;
        bool selecionado;
        bool ativo;
        bool clicado;
    public:
        Botao();
        Botao(const sf::Vector2f& tam, const sf::Vector2f& pos, const string& texto);
        ~Botao();
        void setPos(const sf::Vector2f& pos);
        void setTam(const sf::Vector2f& tam);
        void setTexto(const string& texto);
        void setFonte(const string& caminho);
        void setCorTexto(const sf::Color& cor);
        void setCorRet(const sf::Color& cor);
        void setSelecionado(const bool& selec);
        void setAtivo(const bool& ativo);
        void desenhar();
        void atualizar();
        void executar();
};