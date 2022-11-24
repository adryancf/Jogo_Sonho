#include "Caixa.h"

Caixa::Caixa()
{
}

Caixa::Caixa(const sf::Vector2f tam, const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	//corpo.setFillColor(sf::Color::Red);

	//texture.loadFromFile("freetileset/png/Object/Crate.png");
	//corpo.setTexture(&texture);

	id = ID::caixa;

	/*
	texture.loadFromFile("assets/NinjaFrog.png");
	corpo.setTexture(&texture);
	corpo.setSize(sf::Vector2f(80.0f, 80.0f));
	*/
}

Caixa::~Caixa()
{
}

void Caixa::atacar(Entidade* adversario, float dano)
{
}

void Caixa::Executar()
{
}

void Caixa::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}
