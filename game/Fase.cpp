#include "Fase.h"

Fase::Fase(Jogador *j)
{
	j1 = j;

	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_entidades = new ListaEntidades;
	lista_entidades->listEnt.push(j1);
	
	//INICIALIZA as entidades da fase
	criar_entidades();
}

Fase::~Fase()
{
	//Chama a destrutora da lista?
	delete lista_entidades;
}

void Fase::Executar()
{
}

void Fase::criar_entidades()
{
	//Implementação de mais de um inimigo (terminar depois)

	/*/
	//Cria de 3 a 10 inimigos
	int num_inimigos = 3 + rand() % 10;

	for (int i = 0; i < num_inimigos; i++) {
		aux = new Inimigo;
		aux->setWindow(window);
		lista_entidades->listEnt.push(aux);
		delete aux;
	}
	/*/

	i1 = new Inimigo(j1);
	lista_entidades->listEnt.push(i1);

}

ListaEntidades* Fase::getListaEntidades()
{
	return lista_entidades;
}
