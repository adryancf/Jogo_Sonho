#include "Jogador.h"

Jogador::Jogador(){}

Jogador::~Jogador(){}

void Jogador::mover()
{
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        corpo.move(Vector2f(0.1f, 0.0f));
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        corpo.move(Vector2f(0.0f, 0.1f));
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        corpo.move(Vector2f(-0.1f, 0.0f));
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        corpo.move(Vector2f(0.0f, -0.1f));
    }

}

void Jogador::Executar()
{
    mover();
}

void Jogador::setName(const string a)
{
	nome = a;
}

const string Jogador::getName() const
{
	return nome;
}
