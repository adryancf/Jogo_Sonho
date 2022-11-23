#pragma once

#include "Hydra.h"
#include "Jogador.h"
#include "Dragao.h"
#include "Anjo.h"
#include "Plataforma.h"
#include "Caixa.h"
#include "Espinho.h"
#include "ListaEntidades.h"

#include "GerenciadorColisoes.h"
#include "Ente.h"


class Fase: virtual public Ente
{
protected:

	//Entidades
	Jogador* j1;
	Hydra* hydra;
	Plataforma* plataforma_fase;
	Caixa* caixa;

	//Lista
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;

	//Colisoes
	GerenciadorColisoes* pColisoes;

	//Controle e inicialização
	unsigned int numero_instancias;
	bool ativa;
	virtual void criar_entidades() = 0;

public:
	Fase(Jogador *j);
	~Fase();

	int gerarNumeroAleatorio(int min, int max);
	int gerarNumeroAleatorio(float min, float max);

	void verificaTerminoFase();
	const bool getAtiva();

	virtual void Executar() = 0;

	virtual void criarLista();
	void deletaListas();
	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	virtual void criarCaixa() = 0;
	virtual void criarPlataforma() = 0;
	virtual void criarHydra() = 0;

};

