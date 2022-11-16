#pragma once

#include "Hydra.h"
#include "Jogador.h"
#include "Dragao.h"
#include "Plataforma.h"

#include "ListaEntidades.h"
#include "Ente.h"


class Fase: virtual public Ente
{
protected:
	//ListaEntidades* lista_entidades;
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;

	Jogador* j1;

	//Cria as entidades presentes na fase (Inimigos, Obstaculos) e adciona na lista de entidades
	void criar_entidades();

public:
	Fase(Jogador *j);
	~Fase();

	void Executar();

	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	void criarPlataforma();
	void criarDragao();
	void criarHydra();

	

};

