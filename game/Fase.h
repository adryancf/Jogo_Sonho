#pragma once

#include "Hydra.h"
#include "Jogador.h"
#include "Dragao.h"
#include "Anjo.h"
#include "Plataforma.h"
#include "Caixa.h"
#include "Espinho.h"
#include "ListaEntidades.h"

#include "Ente.h"


class Fase: virtual public Ente
{
protected:

	//Entidades
	Jogador* j1;
	Plataforma* plataforma_fase;
	Caixa* caixa;

	//Lista
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;

	//Controle e inicialização
	unsigned int numero_instancias;
	virtual void criar_entidades() = 0;

public:
	Fase(Jogador *j);
	~Fase();

	int gerarNumeroAleatorio(int min, int max);
	int gerarNumeroAleatorio(float min, float max);

	virtual void Executar() = 0;

	virtual void criarLista();
	void deletaListas();
	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	virtual void criarCaixa() = 0;
	virtual void criarPlataforma() = 0;
};

