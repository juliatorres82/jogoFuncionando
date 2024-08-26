#include "../includes/Jogo.h"

Jogo::Jogo():
plataforma1(sf::Vector2f(200.f, 300.f), 0, sf::Vector2f(200.f, 40.f)),
plataforma2(sf::Vector2f(0.f, 300.f), 0, sf::Vector2f(200.f, 40.f)),
plataforma3(sf::Vector2f(400.f, 200.f),0, sf::Vector2f(200.f, 40.f))
{
    
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    gerenciador_colisoes = Gerenciadores::Gerenciador_Colisoes::getInstancia();
    gerenciador_eventos = Gerenciadores::Gerenciador_Eventos::getGerenciadorEventos();
    //gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
    janela_jogo = gerenciador_grafico->getJanela();   

    jogador2 = nullptr;
    jogador1.setGG(gerenciador_grafico);
    
    inimigo1.setGG(gerenciador_grafico);
    fantasma1.setGG(gerenciador_grafico);

    plataforma1.setGG(gerenciador_grafico);
    plataforma2.setGG(gerenciador_grafico);
    plataforma3.setGG(gerenciador_grafico);

    inimigo1.setJogador(&jogador1);
    fantasma1.setJogador(&jogador1);

    gerenciador_colisoes->incluirObstaculos(&plataforma1);
    gerenciador_colisoes->incluirObstaculos(&plataforma2);
    gerenciador_colisoes->incluirObstaculos(&plataforma3);

    gerenciador_colisoes->incluirInimigos(&inimigo1);
    gerenciador_colisoes->incluirInimigos(&fantasma1);

    gerenciador_colisoes->incluirJogador(&jogador1);
    
    jogador1.setPosicao(100.f, 100.f);
    inimigo1.setPosicao(300.f, 100.f);
    fantasma1.setPosicao(200.f, 100.f); 
}

Jogo::~Jogo()
{
    delete jogador2;
    janela_jogo = nullptr;
}

void Jogo::Executar()
{
    
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

    }
}