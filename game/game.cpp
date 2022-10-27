
#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(800, 600), "Jogo");

    //Vector2f -> Vetor de duas posições (x,y) float
 
    RectangleShape c; //TODAS AS FORMAS DO JOGO VAO SER RETANGULOS

    //VISUAL DO OBJETO
    shape.setFillColor(Color::Magenta);

    //A cada iteração, é um frame
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

    

    return 0;
}
