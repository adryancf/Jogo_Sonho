#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
class Caixa : public Obstaculo
{
private:
	sf::Texture texture;

public:
	Caixa();
	Caixa(const sf::Vector2f tam, const sf::Vector2f pos);
	~Caixa();

	virtual void atacar(Entidade* adversario, float dano);
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

};

