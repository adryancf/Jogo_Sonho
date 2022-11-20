#pragma once

#include "Entidade.h"
#include "Lista.h"


class ListaEntidades
{
private:
	Lista<Entidade> lista;
public:
	ListaEntidades();
	~ListaEntidades();

	void attTudo(float deltaTime);
	void renderTudo();
	void adicionar(Entidade* pE);
	void remover(Entidade* pE);
	void removerTudo();
	void removerTudoExcetoJogador(); //pensar num nome melhor
	const Lista<Entidade>* getList();
	Entidade* operator[](int x);
	int getTamanho();



};

