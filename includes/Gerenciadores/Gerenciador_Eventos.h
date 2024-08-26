#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Jogador.h"
#include <vector>
using namespace Entidades::Personagens;
using namespace std;

namespace Gerenciadores{

    class Gerenciador_Eventos {


        private: // Aplicando Singleton:

            static Gerenciador_Eventos* pGE; 
            Gerenciador_Eventos();
            Gerenciador_Grafico* pGG; // para resgatarmos as janelas
            sf::Event evento;
            Entidades::Personagens::Jogador* jog1 = nullptr; // para resgatarmos os jogadores
            std::vector<sf::Keyboard::Key> vetorTeclasJog;
            std::vector<sf::Keyboard::Key> vetorTeclasGG;

        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* getGerenciadorEventos();
            void setJogador(Jogador* j1, Jogador* j2 = NULL);
            void setGerenciadorGrafico(Gerenciador_Grafico* gg);
            const bool isDoisJogadores();
            const bool haEventos();
            bool teclaSolta(sf::Keyboard::Key tecla);
            bool teclaPressionada(sf::Keyboard::Key tecla);
            void apertaTecla();
            void gerencia();

    };

}