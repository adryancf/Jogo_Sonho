#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entidade
{
protected:
	RectangleShape corpo;
	RenderWindow *janela;

public:
	Entidade();
	~Entidade();

	//Recebe a janela do jogo
	void setWindow(RenderWindow* w);
	void drawWindow();

	virtual void Executar() = 0;

};

