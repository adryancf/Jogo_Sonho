#include "Jogador.h"

Jogador::Jogador():Personagens()
{
    q_vida = 3;
    ID = 1;
    
}


Jogador::Jogador(GerenciadorGrafico* pG)
{
    q_vida = 3;
    pGrafico = pG;
    ID = 1;
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

void Jogador::Colisao(Entidade* entidade)
{
    //Se for com inimigo
    if (entidade->getID() == 2)
    {
        //Se enconstar no inimigo o jogador vai para tras
        this->getCorpo().move(Vector2f(-0.05f, 0.0f));

        //Implementar dano


    }

    //Se for com plataforma
    else if (entidade->getID() == 3)
    {


    }

    else if (entidade->getID() == 4)
    {



    }
}
