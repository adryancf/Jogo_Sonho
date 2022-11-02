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

void Jogador::andar(int i)
{
    std::cout << i << endl;
    if (i == 1)
    {
        corpo.move(Vector2f(0, -speed.y));
    }
    else if (i == 2)
    {
        corpo.move(Vector2f(-speed.x, 0));
    }

    else if (i == 3)
    {
        corpo.move(Vector2f(0, speed.y));
    }
    else if (i == 4)
    {
        corpo.move(Vector2f(speed.x, 0));
    }

}

void Jogador::Mover()
{
   
}

void Jogador::Executar()
{
    Mover();
}
