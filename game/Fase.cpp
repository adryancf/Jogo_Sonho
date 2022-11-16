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
