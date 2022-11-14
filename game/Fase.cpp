#include "Fase.h"

Fase::Fase(Jogador *j)
{
	j1 = j; //Ponteiro para o jogador

	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_personagem = new ListaEntidades;
	lista_obstaculos = new ListaEntidades;

	lista_personagem->listEnt.push(j1);

	//Inicializa todas as entidades da fase
	criar_entidades();
}

Fase::~Fase()
{
	//TODO O NEW TEM DELETE
	delete lista_personagem;
	delete lista_obstaculos;

	//Aterrando ponteiros
	j1 = nullptr;
}

void Fase::Executar()
{
	//Percorrer as listas
}

void Fase::criar_entidades()
{
	criarPlataforma();
	criarDragao();
	//criarHydra();

	Hydra* h = new Hydra(j1);
	Entidade* add = static_cast<Entidade*>(h);
	lista_personagem->listEnt.push(h);
}

ListaEntidades* Fase::getListaPersonagem()
{
	return lista_personagem;
	
}

ListaEntidades* Fase::getListaObstaculo()
{
	return lista_obstaculos;
}

void Fase::criarPlataforma()
{
	//Criando as N plataformas
	Plataforma* p1 = new Plataforma(Vector2f(700.f, 40.f), Vector2f(0.f, 620.f));
	lista_obstaculos->listEnt.push(p1);

	Plataforma* p2 = new Plataforma(Vector2f(650.f, 40.f), Vector2f(1280.f - 650.f, 400.f));
	lista_obstaculos->listEnt.push(p2);
}

void Fase::criarDragao()
{
	Dragao* dragao = new Dragao();
	lista_personagem->listEnt.push(dragao);
}
/*
void Fase::criarHydra()
{
	Hydra* hydra = new Hydra(j1);
	lista_personagem->listEnt.push(hydra);

}
*/