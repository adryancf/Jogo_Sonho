#include "Fase.h"



Fase::Fase(Jogador *j)
{
	j1 = j; //Ponteiro para o jogador
}

Fase::~Fase()
{
	
	//Aterrando ponteiros
	j1 = nullptr;
}

void Fase::Executar()
{
	//Percorrer as listas
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
