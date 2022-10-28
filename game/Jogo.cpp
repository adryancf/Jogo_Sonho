#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(800, 600), "Jogo")
{
    //Alocando ele dinamicâmente (O NEW É O EQUIVALENTE AO MALLOC EM C)
    Jogador1 = new Jogador();

    Jogador1->setWindow(&window);

    fase1 = new Fase(Jogador1, &window);
    //CONHENCENDO A LISTA DE ENTIDADES
    l1 = fase1->getListaEntidades();

    
    executar();
}

Jogo::~Jogo()
{
    delete Jogador1;
}

void Jogo::executar()
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
                window.close();
        }

        window.clear();

        for (int i = 0; i < l1->listEnt.getTamanho(); i++)
        {
            Entidade* aux = l1->listEnt.getItem(i);
            aux->drawWindow();
            aux->Executar();
        }
        

        window.display();
    }
}
