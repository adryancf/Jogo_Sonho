#pragma once


#include "Inimigo.h"
#include <cmath>
#include "Jogador.h"


class Hydra: public Inimigo
{
private:
	Jogador* player;
	Vector2f raio_detecção;

public:
	Hydra(Jogador* p);
	~Hydra();

	void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);

	virtual void Mover();
	virtual void Executar();

};

//Como funciona a Hydra
/*
	Ela persegue o Jogador quando é atacada
	Fica parada ate o jogador a atingir

	O seu ataque nao move o jogador

*/
