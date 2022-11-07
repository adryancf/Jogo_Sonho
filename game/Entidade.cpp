#include "Entidade.h"

Entidade::Entidade(): corpo(Vector2f(100.f, 100.f))
{
    //Posicao padrao de todas as entidades
    corpo.setPosition(Vector2f(30.f, 500.f));
    ID = 0;
}


Entidade::~Entidade(){}

RectangleShape Entidade::getCorpo(){ return corpo; }

const int Entidade::getId()
{
    return ID;
}


