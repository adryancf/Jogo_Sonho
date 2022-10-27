#include "Entidade.h"

Entidade::Entidade(): corpo(Vector2f(100.f, 100.f)), janela(NULL) {}

Entidade::~Entidade(){}

void Entidade::setWindow(RenderWindow* w) { this->janela = w; }

void Entidade::drawWindow() { janela->draw(corpo); }
