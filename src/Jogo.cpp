#include "../includes/Jogo.h"
// Include the header file for Gerenciador_Estados

Jogo::Jogo()
{
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    gerenciador_inputs = Gerenciadores::Gerenciador_Inputs::getInstancia();
    gerenciador_eventos = Gerenciadores::Gerenciador_Eventos::getGerenciadorEventos();
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
    if(gerenciador_grafico == nullptr || gerenciador_eventos == nullptr || gerenciador_estados == nullptr)
    {
        std::cerr << "Erro ao criar os gerenciadores" << '\n';
        exit(1);
    }
    try
    {      
        gerenciador_estados->criarEstados();

        if(gerenciador_estados->getEstado("MenuPrincipal") == nullptr)
            throw "Erro ao criar os estados";
    }

    catch(const char* e)
    {
        std::cerr << e << '\n';
        exit(1);
    }
   /* jogador2 = nullptr;
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
    */
}

Jogo::~Jogo()
{
    //delete jogador2;
    //janela_jogo = nullptr;
}
void Jogo::Executar()
{   
    int dt = 100;
    while (gerenciador_grafico->janelaAberta())
    {
        gerenciador_eventos->gerenciaEventos();

        gerenciador_grafico->limpaJanela();
        
        gerenciador_estados->executar();
        
        if(gerenciador_grafico->janelaAberta())
            gerenciador_grafico->mostrarJanela();
            

    }
        
}