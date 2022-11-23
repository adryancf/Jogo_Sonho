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
    //deletaFase1();

    fase2 = new Fase2(Jogador1);

    lista_personagem = fase2->getListaPersonagem();
    lista_obstaculos = fase2->getListaObstaculo();

    pColisoes->setListas(lista_personagem, lista_obstaculos);



}

void Jogo::controleFases()
{
    if (Jogador1->getVida() == true) {
        if (fase1->getAtiva())
        {
            fase1->Executar();
            fase1->verificaTerminoFase();
        }
        else
        {

            if (fase2 == nullptr)
                iniciaFase2();

            if (fase2->getAtiva()) {
                fase2->Executar();
                fase2->verificaTerminoFase();
            }
            else
                cout << "FIM!!" << endl;
        }
    }
    else
        cout << "FIM DO JOGO!" << endl; //tela de gameOver
}

void Jogo::Executar()
{
    
    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();

        pGrafico->atualizaTempo();

        pGrafico->limpar();
  
        //Desenho as entidades da fase na tela e gerencio as colisoes entre elas dentro de cada fase
        controleFases();

        pGrafico->mostrar();
               
    }

}
