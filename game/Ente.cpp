#include "Ente.h"

//Atributo estatico
//GerenciadorGrafico* GerenciadorGrafico::pGrafico = pGrafico->getGerenciadorGrafico();

Ente::Ente(): pGrafico(pGrafico->getGerenciadorGrafico())
{
	pGrafico->getWindow()->setVerticalSyncEnabled(true);
	visivel = true;
	id = ID::vazio;
}

Ente::Ente(GerenciadorGrafico* pG)
{
	visivel = true;
	pGrafico = pG;
	id = ID::vazio;
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

//Def se estah visivel ou nao
void Ente::setVisivel(bool s)
{
	visivel = s;
}

//Retorna o valor do atributo isShowing
const bool Ente::getVisivel() const
{
	return visivel;
}
