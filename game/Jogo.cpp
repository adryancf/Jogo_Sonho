#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento())
{

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    //Jogador1 = new Jogador(pGrafico);
    Jogador1 = new Jogador();
    fase1 = new Fase(Jogador1);
    pEvento->setJogador(Jogador1);
    
    //CONHENCENDO A LISTA DE ENTIDADES
    l1 = fase1->getListaEntidades();

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
        for (int i = 0; i < l1->listEnt.getTamanho(); i++)
        {
            Entidade* aux = l1->listEnt.getItemLista(i);
            aux->Executar();
            pGrafico->desenhar(aux->getCorpo());
        }
        pGrafico->mostrar();
               
    }

}
