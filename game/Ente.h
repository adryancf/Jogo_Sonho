#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Ente
{
protected:
	RenderWindow* window;


public:
	Ente();
	~Ente();
		
	virtual void Executar() = 0;
	void Print();


};

