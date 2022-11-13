#pragma once

#include "Jogador.h"
#include "Inimigo.h"

#include "Plataforma.h"

#include "ListaEntidades.h"
#include "Ente.h"


//Posteriormente talvez seja inteligente alterar para um virtual public
class Fase: public Ente
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

