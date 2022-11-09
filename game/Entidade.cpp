#include "Entidade.h"

Entidade::Entidade(): corpo(Vector2f(70.f, 70.f)), Ente()
{
    //Posicao padrao de todas as entidades
    corpo.setPosition(Vector2f(200.f, 500.f));
    ID = 0;
}


Entidade::~Entidade(){}

RectangleShape Entidade::getCorpo(){ return corpo; }

const int Entidade::getId()
{
    return ID;
}

void Entidade::setColisao(bool a)
{
    colisao = a;
}

void Entidade::setPosEntidade(Vector2f pos)
{
    corpo.setPosition(pos);
}


