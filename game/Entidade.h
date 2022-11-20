#pragma once
#include "Ente.h"

//Derivando como virtual public
class Entidade : virtual public Ente
{
private:
	//Flag utilizada para fazer desaparecer certas Entidades
	bool showing;

protected:
 
	//As entidades tem uma velocidade
	sf::Vector2f velocidade;

	//As entidades tem um HITBOX, ou seja, uma determinada regiao que pode ser acertado
	sf::Vector2f hitbox;

public:
	//Construtora/Destrutora
	Entidade(ID idD, sf::Vector2f posicaoO, sf::Vector2f hit);
	Entidade();
	virtual ~Entidade();

	//Define a velocidade
	void setVelocidade(sf::Vector2f vel);
	//Retorna a velocidade
	sf::Vector2f getVelocidade();

	//Define o hitbox
	void setHitbox(sf::Vector2f hit);
	//Retorna o hitbox
	sf::Vector2f getHitbox();
	

	//Define o showing
	void setShowing(bool s);
	//Retorna o status do showing
	bool getShowing();
};

