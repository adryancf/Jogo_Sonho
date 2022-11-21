#include "Ente.h"

//Atributo estatico
//GerenciadorGrafico* GerenciadorGrafico::pGrafico = pGrafico->getGerenciadorGrafico();

Ente::Ente(): pGrafico(pGrafico->getGerenciadorGrafico())
{
	pGrafico->getWindow()->setVerticalSyncEnabled(true);
}

Ente::Ente(GerenciadorGrafico* pG)
{
	pGrafico = pG;
}

Ente::~Ente()
{ 
}


// (Sem uso)
void Ente::setWindow(GerenciadorGrafico* pG) 
{ 
	pGrafico = pG; 
}
// (Sem uso) | talvez precise do static antes da declaração da funcao
GerenciadorGrafico* Ente::getGrafico()
{
	return pGrafico;
}

//Pode ser a funcao render (pensar)
void Ente::Print()
{
}

//Define o ID
void Ente::setId(ID Id)
{
	id = Id;
}

//Retorna o ID
ID Ente::getId()
{
	return id;
}
