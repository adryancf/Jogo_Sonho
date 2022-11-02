#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(1280, 720), "Jogo")
{
   
    window.setVerticalSyncEnabled(true);

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    Jogador1 = new Jogador(&window);
    fase1 = new Fase(Jogador1, &window);
    
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
    while (window.isOpen())
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
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed) 
            {

                window.close();
            }
            else if (event.type == Event::KeyPressed) 
            {

                if (event.key.code == Keyboard::Escape)
                    window.close();

            }

            window.clear();
            
            for (int i = 0; i < l1->listEnt.getTamanho(); i++)
            {
                Entidade* aux = l1->listEnt.getItem(i);
                aux->Executar();
                aux->drawWindow();
            }

            window.display();
            

        }
    }

}
