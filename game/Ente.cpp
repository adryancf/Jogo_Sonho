#include "Ente.h"

//Seta o GerenciadorGrafico de uma vez por todas
GerenciadorGrafico* GerenciadorGrafico::pGrafico = pGrafico->getGerenciadorGrafico();

Ente::Ente(ID iD, sf::Vector2f posS)
{
	//pGrafico = pGrafico->getGerenciadorGrafico();
	id = iD;
	posicao = posS;
}

Ente::Ente()
{
	//pGrafico = pGrafico->getGerenciadorGrafico();
	id = eEmpty;
	posicao = sf::Vector2f(0.f, 0.f);
}


Ente::~Ente()
{
}

void Ente::setId(ID idD)
{
	id = idD;
}

const ID Ente::getId()
{
	return id;
}

const sf::Vector2f Ente::getPosicao()
{
	return posicao;
}

void Ente::trocarPosicao(sf::Vector2f pos)
{
	posicao = pos;
}

void Ente::moverPosicao(sf::Vector2f pos)
{
	posicao.x += pos.x;
	posicao.y += pos.y;
}

void Ente::render()
{
	pGrafico->desenhar(corpo);
}

GerenciadorGrafico* Ente::getGrafico()
{
	return pGrafico;
}
