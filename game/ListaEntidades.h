#pragma once

#include "Entidade.h"
#include "Lista.h"


class ListaEntidades
{
public:
	ListaEntidades();
	~ListaEntidades();

	Lista<Entidade> listEnt;

};

