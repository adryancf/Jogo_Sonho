#pragma once

#include "Jogador.h"
#include "Inimigo.h"

#include "ListaEntidades.h"
#include "Ente.h"


class Fase: public Ente
{
private:
	ListaEntidades* lista_entidades;
	Inimigo* i1;
	Jogador* j1;

	//Cria as entidades presentes na fase (Inimigos, Obstaculos) e adciona na lista de entidades
	void criar_entidades();

public:
	Fase(Jogador *j, GerenciadorGrafico* pG);
	~Fase();

	void Executar();

	ListaEntidades* getListaEntidades();


	

};

