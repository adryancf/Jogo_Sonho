#pragma once
#include "ListaEntidades.h"
#include <utility>
#include <cmath>

class GerenciadorColisoes
{
private:
	ListaEntidades* lista; // o gerenciador conhece uma lista de entidades
public:
	GerenciadorColisoes(ListaEntidades* pLista = nullptr);
	~GerenciadorColisoes();
	void colidir();
	void setLista(ListaEntidades* pLista);
	void moverX(Entidade* e1, Entidade* e2, float iX);
	void moverY(Entidade* e1, Entidade* e2, float iY);
	void cima(Entidade* e1, Entidade* e2, float iX, float dx);
	void colidirJogador(Entidade* e1, Entidade* e2, float dx, float dy, float iX, float iY);
	void colidirInimigo(Entidade* e1, Entidade* e2, float dx, float dy, float iX, float iY);
	void colidirProjetil(Entidade* e1, Entidade* e2, float dx, float dy, float iX, float iY);
	void colidirPlataforma(Entidade* e1, Entidade* e2, float dx, float dy, float iX, float iY);
	void atacarInimigo(Entidade* e1, Entidade* e2);
	void atacarJogador(Entidade* e1, Entidade* e2, float dx, float dy);
};
