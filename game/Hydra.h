#pragma once

#include "Inimigo.h"
#include <cmath>
#include "Jogador.h"

//Como funciona a Hydra
/*
	Ela persegue o Jogador quando é atacada
	Fica parada ate o jogador a atingir

	O seu ataque nao move o jogador
 
*/
class Hydra: public Inimigo
{
private:
	Vector2f raio_detecção;
	bool atacou;

	Jogador* jogador1;

public:
	Hydra(Jogador* j);
	~Hydra();

	virtual void Mover();
	virtual void Executar();

	void setAtacou(bool ataque);
	void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);



};

