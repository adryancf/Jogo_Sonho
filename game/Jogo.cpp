#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(1280, 720), "Jogo")
{

    window.setVerticalSyncEnabled(true);

    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    Jogador1 = new Jogador();

    Jogador1->setWindow(&window);

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
    
    //COMO FAZER PARA ISSO FUNCIONAR???

    /* Quero inicializar a janela fora da construtora */
    
    //window.setSize(Vector2u(800, 600));
    //window.setTitle(sf::String("Jogo"));
    
    //LOOP DE EXECUÇÃO DO PROGRAMA
    while (window.isOpen())
    {
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
