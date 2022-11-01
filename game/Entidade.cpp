#include "Entidade.h"

Entidade::Entidade(): corpo(Vector2f(100.f, 100.f)){}

Entidade::~Entidade(){}

void Entidade::setWindow(RenderWindow* w) { this->window = w; }

void Entidade::drawWindow() { window->draw(corpo); }

RectangleShape Entidade::getCorpo()
{
    return corpo;
}


