#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(800, 600), "Jogo")
{
    Jogador1.setWindow(&window);
    Inimigo1.setWindow(&window);
    executar();
}

Jogo::~Jogo()
{
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

        Jogador1.drawWindow();
        Jogador1.Executar();

        Inimigo1.drawWindow();
        Inimigo1.Executar();

        window.display();
    }
}
