#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


/* Derivados de Ente -> Jogo, Entidade, Fase */

class Ente
{
protected:

	//Contem um ponteiro para a janela do jogo (atualmente inicializada na classe jogo) | TODO ENTE CONHECE UMA JANELA
	RenderWindow* window;

public:
	Ente();
	~Ente();
		
	//void setWindow(RenderWindow* w);

	virtual void Executar() = 0;
	void Print();


};

