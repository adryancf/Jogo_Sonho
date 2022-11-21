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
	//Cada fase tem a sua lista, quando essa acabar, deleta essa fase e chama a fase dois
	delete lista_personagem;
	delete lista_obstaculos;
}


void Fase1::criar_entidades()
{
	criarPlataforma();
	//criarDragao();
	//criarHydra();
	Anjo* anjo1 = new Anjo(j1);
	lista_personagem->listEnt.push(anjo1);

	anjo1->setPosEntidade(Vector2f(250.f, ALTURAP3 - 150.f)); //Primeira Plataforma

	//Projetil* projetil_anjo = new Projetil(j1);
	//projetil_anjo->setPortador(anjo1);
	//lista_personagem->listEnt.push(projetil_anjo);

	

}

ListaEntidades* Fase1::getListaPersonagem()
{
	if (lista_personagem)
		return lista_personagem;
	else
		return nullptr;
}

ListaEntidades* Fase1::getListaObstaculo()
{
	if (lista_obstaculos)
		return lista_obstaculos;
	else
		return nullptr;
}

void Fase1::criarDragao()
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

void Fase1::criarHydra()
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

void Fase1::criarPlataforma()
{
	//ORDEM DE VISUALIZA��O (CIMA PARA BAIXO)

	Plataforma* p1 = new Plataforma(Vector2f(400.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->listEnt.push(p1);

	Plataforma* p2 = new Plataforma(Vector2f(300.f, ESPESSURA_PLATAFORMA), Vector2f(450.f, ALTURAP2));
	lista_obstaculos->listEnt.push(p2);

	Plataforma* p3 = new Plataforma(Vector2f(650.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_DIR - 650.f, ALTURAP3));
	lista_obstaculos->listEnt.push(p3);

	Plataforma* p4 = new Plataforma(Vector2f(700.f, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP4));
	lista_obstaculos->listEnt.push(p4);
}


//Percorre a lista de entidades
void Fase1::Executar()
{
	for (int j = 0; j < lista_obstaculos->listEnt.getTamanho(); j++)
	{
		Entidade* aux = lista_obstaculos->listEnt.getItemLista(j);
		aux->Executar();
		pGrafico->desenhar(aux->getCorpo());
	}

	//Implementar isso na classe da lista (se tiver tempo)
	for (int i = 0; i < lista_personagem->listEnt.getTamanho(); i++)
	{
		Entidade* personagem = lista_personagem->listEnt.getItemLista(i);
		if (personagem->getVisivel() == true) {
			personagem->Executar();
			pGrafico->desenhar(personagem->getCorpo());
		}
	}

}
