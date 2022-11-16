#include "Fase.h"

#define ESPESSURA_PLATAFORMA 35.f

#define BORDA_ESQ 0.f
#define BORDA_DIR 1280.f

#define ALTURAP1 120.f
#define ALTURAP2 250.f
#define ALTURAP3 400.f
#define ALTURAP4 620.f

#define ALTURA_HYDRA 60.f
#define ALTURA_DRAGAO 70.f

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
	//ORDEM DE VISUALIZAÇÃO (CIMA PARA BAIXO)

	Plataforma* p1 = new Plataforma(Vector2f(400.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->listEnt.push(p1);

	Plataforma* p2 = new Plataforma(Vector2f(300.f, ESPESSURA_PLATAFORMA), Vector2f(450.f, ALTURAP2));
	lista_obstaculos->listEnt.push(p2);

	Plataforma* p3 = new Plataforma(Vector2f(650.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_DIR - 650.f, ALTURAP3));
	lista_obstaculos->listEnt.push(p3);

	Plataforma* p4 = new Plataforma(Vector2f(700.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP4));
	lista_obstaculos->listEnt.push(p4);

}

void Fase::criarDragao()
{
	Dragao* dragao1 = new Dragao();
	lista_personagem->listEnt.push(dragao1);
	dragao1->setPosEntidade(Vector2f(250.f, ALTURAP1 - ALTURA_DRAGAO)); //Primeira Plataforma

	Dragao* dragao2 = new Dragao();
	lista_personagem->listEnt.push(dragao2);
	dragao2->setPosEntidade(Vector2f(1200.f, ALTURAP3 - ALTURA_DRAGAO)); //Terceira Plataforma

	Dragao* dragao3 = new Dragao();
	lista_personagem->listEnt.push(dragao3);
	dragao3->setPosEntidade(Vector2f(500.f, ALTURAP4 - ALTURA_DRAGAO)); //Quarta Plataforma

}

void Fase::criarHydra()
{
	Hydra* hydra1 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra1);
	hydra1->setPosEntidade(Vector2f(150.f, ALTURAP1 - ALTURA_HYDRA)); //Primeira Plataforma


	Hydra* hydra2 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra2);
	hydra2->setPosEntidade(Vector2f(600.f, ALTURAP2 - ALTURA_HYDRA)); //Segunda Plataforma


	Hydra* hydra3 = new Hydra(j1);
	lista_personagem->listEnt.push(hydra3);
	hydra3->setPosEntidade(Vector2f(100.f, ALTURAP4 - ALTURA_HYDRA)); //Quarta Plataforma


}
