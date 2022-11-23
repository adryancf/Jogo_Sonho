#include "Fase2.h"

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


Fase2::Fase2(Jogador* j1): Fase(j1), anjo(nullptr), projetil_anjo(nullptr)
{
	criar_entidades();
}


Fase2::~Fase2()
{
	deletaListas();
}

void Fase2::criar_entidades()
{
	criarLista();
	criarPlataforma();
	criarAnjo();

}


void Fase2::criarAnjo()
{
	
	srand(time(NULL));

	//(numero de instancias entre 3 e 5)
	numero_instancias = gerarNumeroAleatorio(3, 5);

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
			anjo->setPosEntidade(Vector2f(gerarNumeroAleatorio(100.0f, COMPRIMENTOP1), ALTURAP1 - ANJO_Y)); //Primeira Plataforma

		else if (i == 2)
			anjo->setPosEntidade(Vector2f(gerarNumeroAleatorio(320.0f, COMPRIMENTOP3), ALTURAP3 - ANJO_Y)); //Terceira Plataforma

		else
			anjo->setPosEntidade(Vector2f(gerarNumeroAleatorio(10.0f * i, COMPRIMENTOP5), ALTURAP5 - ANJO_Y)); //Quinta Plataforma

		


	}
}

void Fase2::criarPlataforma()
{
	//ORDEM DE VISUALIZACAO (CIMA PARA BAIXO)
	plataforma_fase = nullptr;

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP1, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP1));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP2, ESPESSURA_PLATAFORMA), Vector2f(700.f, ALTURAP2));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP3, ESPESSURA_PLATAFORMA), Vector2f(320.f, ALTURAP3));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP4, ESPESSURA_PLATAFORMA), Vector2f(BORDA_DIR - 650.f, ALTURAP4));
	lista_obstaculos->incluir(plataforma_fase);

	plataforma_fase = new Plataforma(Vector2f(COMPRIMENTOP5, ESPESSURA_PLATAFORMA), Vector2f(BORDA_ESQ, ALTURAP5));
	lista_obstaculos->incluir(plataforma_fase);
}

void Fase2::criarCaixa()
{
}

void Fase2::Executar()
{
	lista_obstaculos->renderElementos();
	lista_personagem->renderElementos();
}
