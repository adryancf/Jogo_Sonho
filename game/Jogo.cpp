#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento()), fase2(nullptr)
{

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    
    Jogador1 = new Jogador();
    pEvento->setJogador(Jogador1);
  
    iniciaFase1();
    Executar();
}

Jogo::~Jogo()
{
    //Jogador vai ser deletado na destrutora da lista

    //delete fase1;
    delete fase2;
    delete pColisoes;

    lista_obstaculos = nullptr;
    lista_personagem = nullptr;
}



void Jogo::iniciaFase1()
{
    fase1 = new Fase1(Jogador1);

    //CONHENCENDO A LISTA DE ENTIDADES
    lista_personagem = fase1->getListaPersonagem();
    lista_obstaculos = fase1->getListaObstaculo();

    //Posso tratar as colisoes em cada fase
    pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

}

void Jogo::deletaFase1()
{
    if (fase1 != nullptr)
        delete fase1;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO" << endl;
    
    //fase1 = nullptr;
}

void Jogo::iniciaFase2()
{
    fase2 = new Fase2(Jogador1);

    lista_personagem = fase2->getListaPersonagem();
    lista_obstaculos = fase2->getListaObstaculo();

    pColisoes->setListas(lista_personagem, lista_obstaculos);

}

void Jogo::controleFases()
{
    if (fase1->getAtiva())
    {
        fase1->Executar();
        fase1->verificaTerminoFase();
    }
    else
    {
        //deletaFase1();

        if(fase2 == nullptr)
            iniciaFase2();

        if (fase2->getAtiva()) {
            fase2->Executar();
            fase2->verificaTerminoFase();
        }
        else
            cout << "FIM!!" << endl;
    }
}

void Jogo::Executar()
{
    
    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();

        pGrafico->atualizaTempo();

        pGrafico->limpar();
        
        //Se todos os inimigos morrerem a fase acaba
        //Quando a fase 1 acaba, ela é deletada e a fase2 é iniciada
        
        controleFases();
        
        //Verifica Colisões
        pColisoes->verificaColisoes();

        pGrafico->mostrar();
               
    }

}
