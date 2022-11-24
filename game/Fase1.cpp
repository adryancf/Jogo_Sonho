#include "Fase1.h"

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


Fase1::Fase1(Jogador* j1): Fase(j1), fantasma(nullptr)
{
	//Inicializa todas as entidades da fase
	criar_entidades();
	j1->setPosEntidade(Vector2f(10.0f, ALTURAP1 - JOGADOR_Y));

}

Fase1::~Fase1()
{

	deletaListas();

	fantasma = nullptr;

}


void Fase1::criar_entidades()
{
	//Controle
	criarLista();

	//Obstaculos
	criarPlataforma();
	criarCaixa();

	//inimigos
	criarFantasma();
	criarHydra();

}


//Cria de 3 a 4 dragoes na fase e os coloca em uma posicao aleatoria
void Fase1::criarFantasma()
{

	srand(time(nullptr));

	//(numero de instancias entre 3 e 4)
	numero_instancias = gerarNumeroAleatorio(3, 4);

	//Numero aleatorio de instâncias
	for (unsigned int i = 0; i < numero_instancias; i++)
	{
		fantasma = nullptr;

		fantasma = new Fantasma();
		lista_personagem->incluir(fantasma);

		//Setar posicao
		if (i == 0)
			fantasma->setPosEntidade(Vector2f(gerarNumeroAleatorio(150.0f, COMPRIMENTOP1), ALTURAP1 - FANTASMA_Y)); //Primeira Plataforma

		else if(i == 1)
			fantasma->setPosEntidade(Vector2f(gerarNumeroAleatorio(850.0f, 980.f), ALTURAP2 - FANTASMA_Y)); //Segunda Plataforma

		else if (i == 2)
			fantasma->setPosEntidade(Vector2f(gerarNumeroAleatorio(700.0f, 630.f + COMPRIMENTOP4), ALTURAP4 - FANTASMA_Y)); //Quarta Plataforma

		else
			fantasma->setPosEntidade(Vector2f(gerarNumeroAleatorio(50.0f, 500.f), ALTURAP5 - FANTASMA_Y)); //Quinta Plataforma



	}
	
}

//Cria de 3 a 5 hydras na fase e os coloca em uma posicao aleatoria
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
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(320.0f, 600.f), ALTURAP3 - HYDRA_Y)); //Terceira Plataforma

		else
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(10.0f * i, COMPRIMENTOP5), ALTURAP5 - HYDRA_Y)); //Quinta Plataforma


	}

}

//Cria 5 plataformas que formam o cenario da fase
void Fase1::criarPlataforma()
{
	//ORDEM DE VISUALIZA��O (CIMA PARA BAIXO)
	plataforma_fase = nullptr;

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP1, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP2, ESPESSURA_PLATAFORMA_F1), Vector2f(700.f, ALTURAP2));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP3, ESPESSURA_PLATAFORMA_F1), Vector2f(325.f, ALTURAP3));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP4, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_DIR - 650.f, ALTURAP4));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP5, ESPESSURA_PLATAFORMA_F1), Vector2f(BORDA_ESQ, ALTURAP5));
	lista_obstaculos->incluir(plataforma_fase);


}

void Fase1::criarCaixa()
{
	srand(time(nullptr));


	caixa = new Caixa(Vector2f(CAIXA_TAM, CAIXA_TAM), Vector2f(gerarNumeroAleatorio(700.f, 800.f), ALTURAP2 - CAIXA_TAM), true); //Segunda plataforma
	lista_obstaculos->incluir(caixa);

	caixa = new Caixa(Vector2f(CAIXA_TAM, CAIXA_TAM), Vector2f(630.f, ALTURAP4 - CAIXA_TAM), true); //Quarta plataforma
	lista_obstaculos->incluir(caixa);

	caixa = new Caixa(Vector2f(CAIXA_TAM, CAIXA_TAM), Vector2f(630.f, ALTURAP4 - (CAIXA_TAM * 2.f)), true); //Quarta plataforma
	lista_obstaculos->incluir(caixa);

	caixa = new Caixa(Vector2f(CAIXA_TAM, CAIXA_TAM), Vector2f(gerarNumeroAleatorio(630.f + 40.f, 1200.f), ALTURAP4 - CAIXA_TAM), false); //Quarta plataforma
	lista_obstaculos->incluir(caixa);


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
