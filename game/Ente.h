#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/* Jogo, Entidade, Fase */

class Ente
{
protected:
	//Todo ENTE deve conhecer a janela do jogo
	RenderWindow* window;

public:
	Ente();
	~Ente();

	void setWindow(RenderWindow* w);
	
	virtual void Executar() = 0;
	void Print();


};

