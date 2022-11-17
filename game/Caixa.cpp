#include "Caixa.h"

Caixa::Caixa()
{
	id = ID::caixa;
}

Caixa::Caixa(const sf::Vector2f tam, const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(sf::Color::Yellow);
	id = ID::caixa;
}

Caixa::~Caixa()
{
}

void Caixa::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}

void Caixa::Executar()
{
}
