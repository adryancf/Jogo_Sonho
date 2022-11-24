#pragma once

#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Id.h"
/* Derivadas = Jogo, Entidade, Fase */

class Ente
{
protected:
	//Todo ENTE deve conhecer a parte Gráfica do jogo (Janela - SFML)
	GerenciadorGrafico* pGrafico;

	//Todo ENTE tem um ID
	ID id;

	//Todo ENTE tem uma POSICAO

	//Todo ENTE tem um SHAPE

	//Todo ENTE tem uma TEXTURA

	//Todo ENTE pode ou nao estar VISIVEL
	bool visivel;


public:
	Ente();
	Ente(GerenciadorGrafico* pG);
	~Ente();

	void setWindow(GerenciadorGrafico* pG);
	GerenciadorGrafico* getGrafico();

	virtual void Executar() = 0;

	//ID
	void setId(ID Id);
	ID getId();

	//POSICAO

	//TEXTURA

	//VISIBILIDADE
	void setVisivel(bool s);
	const bool getVisivel() const;
};

