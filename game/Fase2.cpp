#include "Fase2.h"

//PLATAFORMAS

#define ALTURAP1 180.f
#define COMPRIMENTOP1 220.f

#define ALTURAP2 250.f
#define COMPRIMENTOP2 180.f

#define ALTURAP3 180.f
#define COMPRIMENTOP3 300.f

#define ALTURAP4 180.f
#define COMPRIMENTOP4 280.f

#define ALTURAP5 475.f
#define COMPRIMENTOP5 180.f

#define ALTURAP6 450.f
#define COMPRIMENTOP6 500.f

#define ALTURAP7 660.f
#define COMPRIMENTOP7 1280.f


Fase2::Fase2(Jogador* j1): Fase(j1), anjo(nullptr), projetil_anjo(nullptr)
{
	criar_entidades();
	j1->setPosEntidade(Vector2f(10.0f, ALTURAP1 - JOGADOR_Y));

}


Fase2::~Fase2()
{
	anjo = nullptr;
	projetil_anjo = nullptr;
	deletaListas();
}

void Fase2::criar_entidades()
{
	criarLista();
	criarPlataforma();
	criarAnjo();
	criarHydra();

}


void Fase2::criarPlataforma()
{
	//ORDEM DE VISUALIZACAO (CIMA PARA BAIXO)
	plataforma_fase = nullptr;

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP1, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP2, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_ESQ + 340.f, ALTURAP2));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP3, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_DIR - COMPRIMENTOP3, ALTURAP3));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP4, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_DIR - (COMPRIMENTOP4 + COMPRIMENTOP3 + 60.f), ALTURAP4));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP5, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_DIR - (COMPRIMENTOP5 + 600.f), ALTURAP5));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP6, ESPESSURA_PLATAFORMA_F2), Vector2f(BORDA_DIR - (COMPRIMENTOP6 + 200.f), ALTURAP6));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP7, ESPESSURA_PLATAFORMA_F2 + 35.f), Vector2f(BORDA_ESQ, ALTURAP7));
	lista_obstaculos->incluir(plataforma_fase);
}

void Fase2::criarCaixa()
{
}

void Fase2::criarAnjo()
{

	srand(time(NULL));

	//(numero de instancias entre 3 e 4)
	numero_instancias = gerarNumeroAleatorio(3, 4);

	//Fazer eles surgirem de tempo em tempo
	// 
	//Numero aleatorio de instancias
	for (int i = 0; i < numero_instancias; i++)
	{
		anjo = nullptr;
		projetil_anjo = nullptr;

		projetil_anjo = new Projetil();
		lista_personagem->incluir(projetil_anjo);

		anjo = new Anjo(j1, projetil_anjo);
		anjo->setAlvo(j1);
		lista_personagem->incluir(anjo);

		projetil_anjo->setPortador(anjo);

		//Posicao
		if (i == 0)
			anjo->setPosEntidade(Vector2f(gerarNumeroAleatorio(650.F, 1000.F), ALTURAP6 - ANJO_Y)); //Sexta Plataforma

		else
			anjo->setPosEntidade(Vector2f(gerarNumeroAleatorio(50.0f, COMPRIMENTOP7), ALTURAP7 - ANJO_Y)); //Setima Plataforma


	}
}

void Fase2::criarHydra()
{
	srand(time(NULL));

	//(numero de instancias entre 3 e 5)
	numero_instancias = gerarNumeroAleatorio(1, 2);

	//Numero aleatorio de instâncias
	for (unsigned int i = 0; i < numero_instancias; i++)
	{
		hydra = nullptr;

		hydra = new Hydra(j1);
		lista_personagem->incluir(hydra);

		//Setar posicao
		if (i == 0)
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(340.0f, COMPRIMENTOP2 + 300.f), ALTURAP2 - HYDRA_Y)); //Segunda Plataforma

		/*
		else if (i == 2)
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(980.0f, 1100.f), ALTURAP3 - HYDRA_Y)); //Terceira Plataforma

		else if(i == 3)
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(640.0f, 900.f), ALTURAP4 - HYDRA_Y)); //Terceira Quarta Plataforma

		*/
		else
			hydra->setPosEntidade(Vector2f(gerarNumeroAleatorio(580.F, 1000.f), ALTURAP6 - HYDRA_Y)); //Sexta Plataforma


	}
}

void Fase2::Executar()
{
	lista_obstaculos->renderElementos();
	lista_personagem->renderElementos();
}
