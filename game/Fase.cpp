#include "Fase.h"

Fase::Fase(Jogador *j)
{
	j1 = j;

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

	//Deletando ponteiros
	i1 = nullptr;
	j1 = nullptr;
}

void Fase::Executar()
{
}

void Fase::criar_entidades()
{

	Plataforma* p1 = new Plataforma(Vector2f(700.f, 40.f), Vector2f(0.f, 620.f));
	lista_obstaculos->listEnt.push(p1);

	Plataforma* p2 = new Plataforma(Vector2f(650.f, 40.f), Vector2f(1280.f - 650.f, 400.f));
	lista_obstaculos->listEnt.push(p2);


	//Implementação de mais de um inimigo (terminar depois)
	//Cria de 3 a 10 inimigos
	int num_inimigos = 4;

	/*
	for (int i = 0; i < num_inimigos; i++) {
		i1 = new Inimigo(j1);

		//DEFINIÇÃO DE COR e Posição
		if (i == 0 && i <= 2) {
			i1->setColor(Color::Magenta);
			//i1->setPosEntidade(Vector2f(150.f, 800.f));

		}
		else if (i > 2 && i <= 4) {
			i1->setColor(Color::Red);
			//i1->setPosEntidade(Vector2f(50.f, 450.f));
		}
		else {
			i1->setColor(Color::Yellow);
			//i1->setPosEntidade(Vector2f(20.f, 600.f));
		}
		// INCLUI NA LISTA DE PERSONAGENS
		lista_personagem->listEnt.push(i1);

		//aux = nullptr;
	}
	*/
	
	i1 = new Inimigo(j1);
	i1->setColor(Color::Yellow);
	lista_personagem->listEnt.push(i1);
	

}

ListaEntidades* Fase::getListaPersonagem()
{
	return lista_personagem;
	
}

ListaEntidades* Fase::getListaObstaculo()
{
	return lista_obstaculos;
}
