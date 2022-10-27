#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"

using namespace std;
using namespace sf;

class Jogo
{
private:
	RenderWindow window;
	Jogador Jogador1;
	Inimigo Inimigo1;

public:
	Jogo();
	~Jogo();

	void executar();


};

