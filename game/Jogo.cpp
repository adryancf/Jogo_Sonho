#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(800, 600), "Jogo"), shape(Vector2f(100.f, 100.f))
{
    shape.setFillColor(Color::Magenta);

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
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            shape.move(Vector2f(0.1f, 0.0f));
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            shape.move(Vector2f(0.0f, 0.1f));
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            shape.move(Vector2f(-0.1f, 0.0f));
        }

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            shape.move(Vector2f(0.0f, -0.1f));
        }


        window.clear();
        window.draw(shape);
        window.display();
    }
}
