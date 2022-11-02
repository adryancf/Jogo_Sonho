#include "Jogador.h"

Jogador::Jogador():Personagens()
{
    q_vida = 3;
    
}


Jogador::Jogador(GerenciadorGrafico* pG)
{
    q_vida = 3;
    pGrafico = pG;
}


Jogador::~Jogador(){}

void Jogador::Mover()
{
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        corpo.move(Vector2f(speed.x, 0));
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        corpo.move(Vector2f(0, speed.y));
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        corpo.move(Vector2f(-speed.x, 0));
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        corpo.move(Vector2f(0, -speed.y));
    }

}

void Jogador::Executar()
{
    Mover();
}
