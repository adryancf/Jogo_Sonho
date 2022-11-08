#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento())
{

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    //Jogador1 = new Jogador(pGrafico);
    Jogador1 = new Jogador();
    fase1 = new Fase(Jogador1);
    pEvento->setJogador(Jogador1);
    
    //CONHENCENDO A LISTA DE ENTIDADES
    lista_personagem = fase1->getListaPersonagem();
    lista_obstaculos = fase1->getListaObstaculo();

    pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

    Executar();
}

Jogo::~Jogo()
{
    delete Jogador1;
}

void Jogo::Executar()
{
    
    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();
        pGrafico->limpar();
        for (int i = 0; i < lista_personagem->listEnt.getTamanho(); i++)
        {
            Entidade* aux = lista_personagem->listEnt.getItemLista(i);
            aux->Executar();
            pGrafico->desenhar(aux->getCorpo());
        }
        pColisoes->verificaColisoes();
        pGrafico->mostrar();
               
    }

}
