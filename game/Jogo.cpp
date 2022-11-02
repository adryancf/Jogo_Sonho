#include "Jogo.h"

Jogo::Jogo() : pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
{
   
    pGerenciadorGrafico->getWindow()->setVerticalSyncEnabled(true);

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    Jogador1 = new Jogador(pGerenciadorGrafico->getWindow());
    fase1 = new Fase(Jogador1, pGerenciadorGrafico->getWindow());
    
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
    const float FPS = 60.0;
    float dt;
    sf::Clock clock;

    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (pGerenciadorGrafico->isWindowOpen())
    {
        /*
        dt = clock.getElapsedTime().asSeconds();
        if (dt < (1.0 / FPS))
        {
            Time t = seconds((1.0f / FPS) - dt);
            sleep(t);
            dt = 1.0f / FPS;
        }
        else { cout << "FPS" << endl; }
        clock.restart();

        window.display();

        */

        Event event;
        while (pGerenciadorGrafico->getWindow()->pollEvent(event))
        {

            if (event.type == Event::Closed) 
            {

                pGerenciadorGrafico->fecharJanela();
            }
            else if (event.type == Event::KeyPressed) 
            {

                if (event.key.code == Keyboard::Escape)
                    pGerenciadorGrafico->fecharJanela();

            }

            pGerenciadorGrafico->limpar();
            
            for (int i = 0; i < l1->listEnt.getTamanho(); i++)
            {
                Entidade* aux = l1->listEnt.getItem(i);
                aux->Executar();
                aux->drawWindow();
            }

            pGerenciadorGrafico->mostrar();
            

        }
    }

}
