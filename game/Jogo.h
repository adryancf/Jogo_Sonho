#pragma once
#include "Fase1.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"

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

	Fase1* fase1;

public:
	Jogo();
	~Jogo();

	void Executar();


};

