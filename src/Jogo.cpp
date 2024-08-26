#include "../includes/Jogo.h"

Jogo::Jogo()
{
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    janela_jogo = gerenciador_grafico->getJanela();
    gerenciador_colisoes = Gerenciadores::Gerenciador_Colisoes::getInstancia();


    jogador2 = nullptr;
    jogador1.setGG(gerenciador_grafico);
    fantasma1.setGG(gerenciador_grafico);
    
    gerenciador_colisoes->incluirInimigos(&fantasma1);
    gerenciador_colisoes->incluirJogador(&jogador1);
    gerenciador_colisoes->incluirObstaculos(&plataforma1);
    gerenciador_colisoes->incluirObstaculos(&plataforma2);  


    plataforma1.setPosicao(200.f, 300.f);
    plataforma2.setPosicao(250.f, 200.f);

    gerenciador_eventos = Gerenciador_Eventos::getGerenciadorEventos();
    gerenciador_eventos->setGerenciadorGrafico(gerenciador_grafico);
    gerenciador_eventos->setJogador(&jogador1);

    //gerenciador_eventos->gerencia();
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
          while (janela_jogo->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela_jogo->close();

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                janela_jogo->close();
        }
        
        gerenciador_colisoes->tratarColisoes();

        janela_jogo->clear();
        
        jogador1.executar();
        fantasma1.executar();
        plataforma1.desenhar();
        plataforma2.desenhar();

        janela_jogo->display();
        
        gerenciador_eventos->gerencia();

    }
}