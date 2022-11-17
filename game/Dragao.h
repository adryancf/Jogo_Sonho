#pragma once

#include "Inimigo.h"

class Dragao: public Inimigo
{

private:
	//Caracteristica do Dragao
	//Pode soltar um projetil
	//Quando o Jogador encosta nele ele é empurrado para o lado e para cima
	//NAO SEGUE O JOGADOR

	float tempo_de_ataque;

public:
	Dragao();
	~Dragao();

	const float getTempoAtaque() const;

	virtual void Mover();
	virtual void Executar();

};

