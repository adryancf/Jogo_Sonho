#pragma once

#include "Ente/Fase/Fase.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorColisoes.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	Jogador* Jogador1;

	//Conhece a lista de entidades da fase para realizar a impressao na tela
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;
	
	GerenciadorEvento* pEvento;
	GerenciadorColisoes* pColisoes;

	Fase* fase1;

public:
	Jogo();
	~Jogo();

	void Executar();


};

