#include "Entidade.h"

Entidade::Entidade(): corpo(Vector2f(100.f, 100.f))
{
    //Posição Padrão de todo corpo
    //corpo.setPosition(Vector2f(30.f, 500.f));
}

Entidade::~Entidade(){}

//NAO PRECISA
void Entidade::setWindow(RenderWindow* w) { this->window = w; }

void Entidade::drawWindow(){
    window->draw(corpo); 
}

RectangleShape Entidade::getCorpo()
{
    return corpo;
}


