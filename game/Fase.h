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
	
	//Nao precisa desse ponteiro para inimigo
	Inimigo* i1;
	
	Jogador* j1;

	sf::RenderWindow* windows;

	//Cria as entidades da fase
	void criar_entidades();

public:
	Fase(Jogador *j, sf::RenderWindow* w);
	//Fase(Jogador* j);

	~Fase();

	void Executar();

	ListaEntidades* getListaEntidades();
	

};

