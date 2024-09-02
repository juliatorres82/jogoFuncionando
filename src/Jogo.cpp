#include "../includes/Jogo.h"

// Include the header file for Gerenciador_Estados

Jogo::Jogo()
{
    gerenciador_grafico = Gerenciadores::Gerenciador_Grafico::getInstancia();
    gerenciador_inputs = Gerenciadores::Gerenciador_Inputs::getInstancia();
    gerenciador_eventos = Gerenciadores::Gerenciador_Eventos::getInstancia();
    gerenciador_estados = Gerenciadores::Gerenciador_Estados::getInstancia();
    cout << gerenciador_grafico->getJanela()->getSize().x << endl;
    cout << gerenciador_grafico->getJanela()->getSize().y << endl;
    if(gerenciador_grafico == nullptr || gerenciador_eventos == nullptr || gerenciador_estados == nullptr || gerenciador_inputs == nullptr)
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
}

Jogo::~Jogo()
{
    delete gerenciador_grafico;
    delete gerenciador_eventos;
    gerenciador_inputs->deletaInstancia();
    delete gerenciador_estados;
}

void Jogo::Executar()
{   
    while (gerenciador_grafico->janelaAberta())
    {
        gerenciador_eventos->gerenciaEventos();

        gerenciador_grafico->limpaJanela();
        
        gerenciador_estados->executar();
        
        if(gerenciador_grafico->janelaAberta())
            gerenciador_grafico->mostrarJanela();
        
    } 
}