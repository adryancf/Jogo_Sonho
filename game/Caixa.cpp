#include "Caixa.h"

Caixa::Caixa()
{
}

Caixa::Caixa(const sf::Vector2f tam, const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(sf::Color::Red);
	ID = 99999;

}

Caixa::~Caixa()
{
}

void Caixa::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}
