#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ente.h"
using namespace std;
using namespace sf;

// :pulic sf::Drawable (?)
class Entidade : public Ente
{
protected:
	RectangleShape corpo;

public:
	Entidade();

	//PODE SER DESTRUTORA VIRTUAL PURA?
	~Entidade();

	//Recebe a janela do jogo
	void setWindow(RenderWindow* w);
	void drawWindow();

	RectangleShape getCorpo();
	
	virtual void Executar() = 0;

};

