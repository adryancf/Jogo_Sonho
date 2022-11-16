#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento())
{

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    
    Jogador1 = new Jogador();

    fase1 = new Fase1(Jogador1);

    pEvento->setJogador(Jogador1);
    
    //CONHENCENDO A LISTA DE ENTIDADES
    lista_personagem = fase1->getListaPersonagem();
    lista_obstaculos = fase1->getListaObstaculo();

    //Posso tratar as colisoes em cada fase
    pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

    Executar();
}

Jogo::~Jogo()
{
    //Jogador vai ser deletado na destrutora da lista

    delete fase1;
    delete pColisoes;

    lista_obstaculos = nullptr;
    lista_personagem = nullptr;
}

void Jogo::Executar()
{
    
    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();

        pGrafico->atualizaTempo();

        pGrafico->limpar();
        
        //Percorre as listas
        fase1->Executar();

        pColisoes->verificaColisoes();

        pGrafico->mostrar();
               
    }

}
