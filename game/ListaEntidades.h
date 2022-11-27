#pragma once

#include "Entidade.h"
#include "Lista.h"


class ListaEntidades
{

private:
	Lista<Entidade> listEnt;

public:
	ListaEntidades();
	~ListaEntidades();

	void renderElementos();
	bool verificaEntidadesVisiveis();
	int contaEntidadesMortas();
	int contaJogadores();

	Entidade* getJogador();
	const int getTamanhoLista();

	void incluir(Entidade* pE);

	void remover(Entidade* pE);
	void removerTudo();
	void removerTudoExcetoJogador();

	const Lista<Entidade>* getList();

	Entidade* operator[](int x);


};

