#include "../includes/Jogo.h"

int main()
{
    Jogo joguinholindo;
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Jogo");
    janela.setFramerateLimit(60);
    sf::RectangleShape retangulo(sf::Vector2f(100.f, 100.f));
    janela.draw(retangulo);
    return 0;
}