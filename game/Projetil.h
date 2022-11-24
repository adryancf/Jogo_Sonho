#pragma once

#include "Entidade.h"
#include "Personagens.h"

//Adicionar SPRITE NO PROJETIL

class Projetil: public Entidade
{
private:
	Personagens* alvo;
	Vector2f posicaoAlvo;

	Personagens* portador;

public:
	Projetil();
	Projetil(Personagens* a);

	~Projetil();

	void setAlvo(Personagens* alvo);
	const Personagens* getAlvo() const;
	void EncontraPosAlvo();

	void estadoInicial();
	void setPortador(Personagens* portador);
	const Personagens* getPortador() const;

	void movimentoProjetil();

	virtual void atacar(Entidade* adversario, float dano);
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

