#pragma once

#include "Hydra.h"
#include "Jogador.h"
#include "Dragao.h"
#include "Anjo.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

#include "Ente.h"


class Fase: virtual public Ente
{
protected:
	Jogador* j1;

	virtual void criar_entidades() = 0;

public:
	Fase(Jogador *j);
	~Fase();

	virtual void Executar() = 0;
	virtual void criarPlataforma() = 0;
};

