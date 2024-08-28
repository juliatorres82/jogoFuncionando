#include "../includes/Jogo.h"

Jogo::Jogo()
{
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    gerenciador_eventos = Gerenciadores::Gerenciador_Eventos::getGerenciadorEventos();
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
}

Jogo::~Jogo()
{
    janela_jogo = nullptr;
}

void Jogo::Executar()
{
   /*
    while (gerenciador_grafico->janelaAberta())
    {
        sf::Event event;
        janela_jogo->setKeyRepeatEnabled(false);
        while (janela_jogo->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                gerenciador_grafico->fecharJanela();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !jogador1.doisJogadores())
            {
                jogador2 = new Jogador(&jogador1);
                gerenciador_colisoes->incluirJogador(jogador2);
                jogador1.setJogador2(jogador2);
                jogador2->setJogador2(&jogador1);
            }

            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                janela_jogo->setKeyRepeatEnabled(true);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    break;
            }

                janela_jogo->setKeyRepeatEnabled(true);

        }
    
        gerenciador_colisoes->tratarColisoes();

        janela_jogo->clear();
        inimigo1.executar();
        fantasma1.executar();
        jogador1.executar();
		if (jogador1.doisJogadores())
			jogador2->executar();
        
        plataforma1.executar();
        plataforma2.executar();
        plataforma3.executar();
             
        janela_jogo->display();

    } */
}