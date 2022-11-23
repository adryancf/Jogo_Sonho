﻿#include "Fase1.h"

//PLATAFORMAS

#define ALTURAP1 120.f
#define COMPRIMENTOP1 600.f

#define ALTURAP2 200.f
#define COMPRIMENTOP2 300.f

#define ALTURAP3 360.f
#define COMPRIMENTOP3 300.f

#define ALTURAP4 450.f
#define COMPRIMENTOP4 650.f

#define ALTURAP5 700.f
#define COMPRIMENTOP5 1000.f


Fase1::Fase1(Jogador* j1): Fase(j1)
{
	//Inicializa todas as entidades da fase
	criar_entidades();
	j1->setPosEntidade(Vector2f(10.0f, ALTURAP1 - JOGADOR_Y));

}

Fase1::~Fase1()
{
	deletaListas();

	dragao = nullptr;
	espinho = nullptr;

}


void Fase1::criar_entidades()
{
	criarLista();
	criarPlataforma();
	criarDragao();
	criarHydra();
}


void Fase1::criarDragao()
{

	srand(time(nullptr));

	//(numero de instancias entre 3 e 5)
	numero_instancias = gerarNumeroAleatorio(3, 4);

	//Numero aleatorio de instâncias
	for (unsigned int i = 0; i < numero_instancias; i++)
	{
		dragao = nullptr;

		dragao = new Dragao();
		lista_personagem->incluir(dragao);

		//Setar posicao
		if (i == 0)
			dragao->setPosEntidade(Vector2f(gerarNumeroAleatorio(150.0f, COMPRIMENTOP1), ALTURAP1 - HYDRA_Y)); //Primeira Plataforma

		else if(i == 1)
			dragao->setPosEntidade(Vector2f(gerarNumeroAleatorio(700.0f, COMPRIMENTOP2), ALTURAP2 - HYDRA_Y)); //Segunda Plataforma

		else if (i == 2)
			dragao->setPosEntidade(Vector2f(gerarNumeroAleatorio(630.0f, 630.f + COMPRIMENTOP4), ALTURAP4 - HYDRA_Y)); //Quarta Plataforma

		else
			dragao->setPosEntidade(Vector2f(gerarNumeroAleatorio(50.0f, COMPRIMENTOP5), ALTURAP5 - HYDRA_Y)); //Quinta Plataforma



	}
	
}

void Fase1::criarHydra()
{
	srand(time(NULL));

	//(numero de instancias entre 3 e 5)
	numero_instancias = gerarNumeroAleatorio(3, 5);

	//Numero aleatorio de instâncias
	for (unsigned int i = 0; i < numero_instancias; i++)
	{
		hydra = nullptr;

		hydra = new Hydra(j1);
		lista_personagem->incluir(hydra);

		//Setar posicao
		if(i == 0)
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(100.0f, COMPRIMENTOP1), ALTURAP1 - HYDRA_Y)); //Primeira Plataforma

		else if(i == 2)
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(320.0f, COMPRIMENTOP3), ALTURAP3 - HYDRA_Y)); //Terceira Plataforma

		else
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(10.0f * i, COMPRIMENTOP5), ALTURAP5 - HYDRA_Y)); //Quinta Plataforma


	}

}



void Fase1::criarPlataforma()
{
	//ORDEM DE VISUALIZA��O (CIMA PARA BAIXO)
	plataforma_fase = nullptr;

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP1, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP2, ESPESSURA_PLATAFORMA_F1), Vector2f(700.f, ALTURAP2));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP3, ESPESSURA_PLATAFORMA_F1), Vector2f(320.f, ALTURAP3));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP4, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_DIR - 650.f, ALTURAP4));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP5, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_ESQ, ALTURAP5));
	lista_obstaculos->incluir(plataforma_fase);


}

void Fase1::criarCaixa()
{

}


//Percorre a lista de entidades
void Fase1::Executar()
{
	//desenha fundo

	//Desenha todas as entidades
	lista_obstaculos->renderElementos();
	lista_personagem->renderElementos();

	//Verifica a colisao entre elas
	pColisoes->verificaColisoes();
}
