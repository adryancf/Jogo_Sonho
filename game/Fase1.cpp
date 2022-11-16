#include "Fase1.h"



#define ALTURAP1 120.f
#define ALTURAP2 250.f
#define ALTURAP3 400.f
#define ALTURAP4 620.f


Fase1::Fase1(Jogador* j1): Fase(j1)
{
	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_personagem = new ListaEntidades;
	lista_obstaculos = new ListaEntidades;

	lista_personagem->listEnt.push(j1);

	//Inicializa todas as entidades da fase
	criar_entidades();
}

Fase1::~Fase1()
{
	//TODO O NEW TEM DELETE
	delete lista_personagem;
	delete lista_obstaculos;
}


void Fase1::criar_entidades()
{
	criarPlataforma();
	criarDragao();
	criarHydra();
}

ListaEntidades* Fase1::getListaPersonagem()
{
	if(lista_personagem)
		return lista_personagem;
}

ListaEntidades* Fase1::getListaObstaculo()
{
	if(lista_obstaculos)
		return lista_obstaculos;
}

void Fase1::Executar()
{
}
