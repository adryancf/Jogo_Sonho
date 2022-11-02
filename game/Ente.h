#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GerenciadorGrafico.h"


using namespace std;
using namespace sf;

/* Jogo, Entidade, Fase */

class Ente
{
protected:
	//Todo ENTE deve conhecer a parte Gráfica do jogo (Janela - SFML)
	GerenciadorGrafico* pGrafico;

public:
	Ente();
	Ente(GerenciadorGrafico* pG);
	~Ente();

	void setWindow(GerenciadorGrafico* pG);
	GerenciadorGrafico* getGrafico();

	
	
	virtual void Executar() = 0;
	void Print();


};

