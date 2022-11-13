#pragma once

#include "Ente/Entidades/Entidade.h"
#include "Listas/Lista/Lista.h"


class ListaEntidades
{
public:
	ListaEntidades();
	~ListaEntidades();

	Lista<Entidade> listEnt;

};

