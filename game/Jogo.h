#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jogador.h"

using namespace std;
using namespace sf;

class Jogo
{
private:
	RenderWindow window;
	Jogador Jogador1;

public:
	Jogo();
	~Jogo();

	void executar();


};

