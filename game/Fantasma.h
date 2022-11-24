#pragma once

#include "Inimigo.h"

class Fantasma: public Inimigo
{

private:
	float tempo_de_ataque;
	//sf::Texture texture;

public:
	Fantasma();
	~Fantasma();

	const float getTempoAtaque() const;
	void inicializa();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

/* Caracteristica do Dragao */

//Quando o Jogador encosta nele ele é empurrado para o lado