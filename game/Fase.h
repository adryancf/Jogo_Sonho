#pragma once
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Inimigo.h"
#include <SFML\Graphics.hpp>


class Fase
{
private:
	ListaEntidades* lista_entidades;
	Inimigo* i1;
	Jogador* j1;

	sf::RenderWindow* window;

	void criar_entidades();

public:
	Fase(Jogador *j, sf::RenderWindow* w);

	~Fase();

	

	ListaEntidades* getListaEntidades();
	

};

