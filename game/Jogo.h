#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Fase.h"

#include "ListaEntidades.h"

using namespace std;
using namespace sf;

class Jogo
{
private:
	RenderWindow window;
	Jogador* Jogador1;

	ListaEntidades* l1;
	
	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void executar();


};

