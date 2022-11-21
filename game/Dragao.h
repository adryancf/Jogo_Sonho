#pragma once

#include "Inimigo.h"

class Dragao: public Inimigo
{

private:
	float tempo_de_ataque;

public:
	Dragao();
	~Dragao();

	const float getTempoAtaque() const;
	void inicializa();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

/* Caracteristica do Dragao */

//Quando o Jogador encosta nele ele é empurrado para o lado