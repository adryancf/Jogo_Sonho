#pragma once
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Inimigo.h"
#include <SFML\Graphics.hpp>
#include "Ente.h"


class Fase: public Ente
{
private:
	ListaEntidades* lista_entidades;
	Inimigo* i1;
	Jogador* j1;

	//sf::RenderWindow* window;

	void criar_entidades();

public:
	Fase(Jogador *j, sf::RenderWindow* w);

	~Fase();

	void Executar();

	ListaEntidades* getListaEntidades();
	

};

