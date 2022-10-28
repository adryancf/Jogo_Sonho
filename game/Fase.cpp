#include "Fase.h"

Fase::Fase(Jogador *j, sf::RenderWindow* w)
{
	j1 = j;
	i1 = new Inimigo;
	lista_entidades = new ListaEntidades;
	window = w;
	i1->setWindow(w);
	inicializa_elementos();
}

Fase::~Fase()
{
	delete lista_entidades;
	delete i1;
}

ListaEntidades* Fase::getListaEntidades()
{
	return lista_entidades;
}

void Fase::inicializa_elementos()
{
	lista_entidades->listEnt.push(j1);
	lista_entidades->listEnt.push(i1);
}
