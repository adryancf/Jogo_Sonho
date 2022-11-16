#pragma once

#include "Fase.h"


class Fase1: public Fase
{
private:
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;

	virtual void criar_entidades();

public:
	Fase1(Jogador* j1);
	~Fase1();

	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	void criarDragao();
	void criarHydra();
	virtual void criarPlataforma();

	virtual void Executar();






};

