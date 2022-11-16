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
	criarHydra();

	
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

	Plataforma* p2 = new Plataforma(Vector2f(650.f, 40.f), Vector2f(1280.f - 650.f, 350.f));
	lista_obstaculos->listEnt.push(p2);

	Plataforma* p3 = new Plataforma(Vector2f(400.f, 40.f), Vector2f(0.f, 200.f));
	lista_obstaculos->listEnt.push(p3);


}

void Fase::criarDragao()
{
	Dragao* dragao1 = new Dragao();
	lista_personagem->listEnt.push(dragao1);
	//posicao do dragao1

	Dragao* dragao2 = new Dragao();
	lista_personagem->listEnt.push(dragao2);
	//posicao do dragao1

	Dragao* dragao3 = new Dragao();
	lista_personagem->listEnt.push(dragao3);
	//posicao do dragao1

}

void Fase::criarHydra()
{
	Hydra* hydra1 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra1);

	//posicao da h1

	Hydra* hydra2 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra2);

	//posicao da h2

	Hydra* hydra3 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra3);

	//posicao da h3


}
