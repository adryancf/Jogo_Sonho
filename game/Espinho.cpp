#include "Espinho.h"

Espinho::Espinho(const sf::Vector2f tam, const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(sf::Color::Magenta);
	id = ID::espinho;
}

/*
Espinho::Espinho(const sf::Vector2f pos, const float radius)
{
	cShape.setRadius(radius);
	cShape.setPosition(pos);
	cShape.setFillColor(sf::Color::Magenta);
	id = ID::espinho;
}

*/
Espinho::~Espinho()
{
}

void Espinho::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}

void Espinho::Executar()
{
}

Espinho::Espinho()
{
	id = ID::espinho;
}
