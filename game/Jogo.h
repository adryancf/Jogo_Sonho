#pragma once
#include "Fase.h"
#include "GerenciadorGrafico.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	GerenciadorGrafico* pGerenciadorGrafico;
	Jogador* Jogador1;

	//Conhece a lista de entidades da fase para realizar a impressao na tela
	ListaEntidades* l1;
	
	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void Executar();


};

