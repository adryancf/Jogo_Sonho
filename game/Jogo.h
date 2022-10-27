#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Jogo
{
private:
	RenderWindow window;
	RectangleShape shape;

public:
	Jogo();
	~Jogo();

	void executar();


};

