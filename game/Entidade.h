#pragma once
#include "Ente.h"

#include <SFML/Graphics.hpp>
#include <iostream>

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
	//Isso ja ta proposto na classe Ente

	void drawWindow();

	RectangleShape getCorpo();
	
	virtual void Executar() = 0;

};

