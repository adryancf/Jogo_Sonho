#include "Jogo.h"
#include "conio.h"
Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento()), fase2(nullptr), fase1(nullptr)
{
    //estado = Estado;

    //Alocando ele dinamic�mente (O NEW � O EQUIVALENTE AO MALLOC EM C)
   
    if (!fase1)
        cout << "!fase1 eh verdadeiro" << endl;

    std::cout << "Constutora de jogo iniciada" << std::endl;
    iniciarMenu();

    //iniciaFase1();
    Executar();

    //Inicializando a textura
    //textura.loadFromFile("assets/h4.png");
    //Corpo.setTexture(&textura);
    //Corpo.setSize(sf::Vector2f(RESOLUCAO_X, RESOLUCAO_Y));
}

Jogo::~Jogo()
{
    //Jogador vai ser deletado na destrutora da lista

    Jogador1 = nullptr;
}



void Jogo::iniciaFase1()
{
    Jogador1 = new Jogador();
    pEvento->setJogador(Jogador1);

    fase1 = new Fase1(Jogador1);

}


void Jogo::deletaFase1()
{
    if (fase1 != nullptr)
        delete fase1;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 1" << endl;

    fase1 = nullptr;
}

void Jogo::iniciaFase2()
{
    if(fase1)
        deletaFase1();

    Jogador1 = new Jogador();
    pEvento->setJogador(Jogador1);

    fase2 = new Fase2(Jogador1);
}

void Jogo::deletaFase2()
{
    if (fase2 != nullptr)
        delete fase2;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 2" << endl;

    fase2 = nullptr;
    Jogador1 = nullptr;
}

void Jogo::iniciarMenu()
{
    std::cout << "Menu Principal iniciado." << std::endl;
    menu = new Menu();
}
/*
void Jogo::setEstado(ID id)
{
    estado = id;
}
*/
void Jogo::controleFases()
{

    if (!fase1)
        iniciaFase1();

    if (Jogador1 && Jogador1->getVida() == true) {


        if (fase1 && fase1->getAtiva())
        {
            fase1->Executar();
            fase1->verificaTerminoFase();
        }

        else
        {
            if (fase2 == nullptr)
                iniciaFase2();

            //cout << "Chamei a fase2" << endl;

            if (fase2->getAtiva()) {
                fase2->Executar();
                fase2->verificaTerminoFase();
            }
            else {
                deletaFase2();
            }
        }
    }
    else {

        if (fase1)
            deletaFase1();
        if (fase2)
            deletaFase2();

        //deletar
        cout << "FIM DO JOGO!" << endl; //tela de gameOver
        //tempo e uma imagem
        pGrafico->fecharJanela();
    }
}
/*
ID Jogo::getEstado()
{
    return estado;
}
*/
void Jogo::Executar()
{
    
    std::cout << "Entrou no loop executar / loop principal." << std::endl;

    //LOOP DE EXECU��O DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        //pEvento->Executar();

        //pGrafico->atualizaTempo();

        //pGrafico->limpar();

        //O problema esta na inicialização do estado!

        ID estado = pGrafico->getEstado();
        std::cout << "Estado: " << estado << std::endl;
        //getch();


        if (estado == ID::menuPrincipal)
        {
            std::cout << "Menu Principal is running." << std::endl;
            menu->run_menu();
        }
        else if (estado == ID::menuPause)
        {

        }

        else if (estado == ID::fase1)
        {
            std::cout << "Fase1 is running" << std::endl;
            pEvento->Executar();
            std::cout << "pEvento->executar com sucesso" << std::endl;
            pGrafico->atualizaTempo();
            std::cout << "Tempo atualizado com sucesso" << std::endl;
            pGrafico->limpar();
            std::cout << "Grafico limpo com sucesso" << std::endl;


            
            controleFases();
            std::cout << "controleFases realizado com sucesso" << std::endl;




            pGrafico->mostrar();
        }
        else if (estado == ID::fase2)
        {

        }
  
        //Desenho as entidades da fase na tela e gerencio as colisoes entre elas dentro de cada fase
        //controleFases();

        //7pGrafico->mostrar();
               
    }

}
