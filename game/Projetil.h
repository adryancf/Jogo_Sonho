#pragma once

#include "Personagens.h"

class Projetil: public Entidade
{
private:

	Personagens* portador;
	bool repouso;

	sf::Clock t;
	float tempo_ataque;

public:
	Projetil();
	~Projetil();


	void verificarBordas();

	void estadoInicial();
	void atualizaPosicaoInicial();
	void setPortador(Personagens* portador);
	const Personagens* getPortador() const;

	virtual void atacar(Entidade* adversario, float dano);
	void atirar(string direcao, float tempo);

	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

