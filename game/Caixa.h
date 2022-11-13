#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
class Caixa : public Obstaculo
{
private:

public:
	Caixa();
	Caixa(const sf::Vector2f tam, const sf::Vector2f pos);
	~Caixa();

	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

};

