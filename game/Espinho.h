#pragma once
#include "Obstaculo.h"
class Espinho : public Obstaculo
{
public:
	Espinho();
	Espinho(const sf::Vector2f tam, const sf::Vector2f pos);
	//Espinho(const sf::Vector2f pos, const float radius = 60.f);
	~Espinho();

	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

	virtual void Executar();
	//sf::CircleShape cShape;
	//inicializar os espinhos
	//void initialize();
private:
	
};

