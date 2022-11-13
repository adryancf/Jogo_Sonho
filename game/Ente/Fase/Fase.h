#pragma once

#include "Ente/Entidades/Personagens/Jogador/Jogador.h"
#include "Ente/Entidades/Personagens/Inimigo/Inimigo.h"

#include "Ente/Entidades/Obstaculos/Plataforma/Plataforma.h"

#include "Listas/ListaEntidades.h"
#include "Ente/Ente.h"


class Fase: virtual public Ente
{
private:
	//ListaEntidades* lista_entidades;
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;
	Inimigo* i1;
	Jogador* j1;

	//Cria as entidades presentes na fase (Inimigos, Obstaculos) e adciona na lista de entidades
	void criar_entidades();

public:
	Fase(Jogador *j);
	~Fase();

	void Executar();

	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	

};

