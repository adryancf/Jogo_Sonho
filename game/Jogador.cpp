#include "Jogador.h"

Jogador::Jogador():Personagens()
{
}

Jogador::~Jogador(){}

void Jogador::Mover()
{
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        corpo.move(Vector2f(velocidade, 0));
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        corpo.move(Vector2f(0, velocidade));
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        corpo.move(Vector2f(velocidade * (-1), 0));
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        corpo.move(Vector2f(0, velocidade * (-1)));
    }

}

void Jogador::Executar()
{
    Mover();
}
