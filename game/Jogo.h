#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"
#include "Menu.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	Jogador* Jogador1;

	//Conhece a lista de entidades da fase para incluir no gerenciador de colisoes
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;
	
	GerenciadorEvento* pEvento;
	GerenciadorColisoes* pColisoes;

	Fase1* fase1;
	Fase2* fase2;
	Menu* menu;
	
	//O jogo tem um ESTADO
	//ID estado;

public:
	Jogo();
	//Jogo(ID Estado = ID::menuPrincipal);
	~Jogo();

	void controleFases();

	void iniciaFase1();
	void deletaFase1();
	void iniciaFase2();
	void deletaFase2();

	void iniciarMenu();

	//Metodo para definir o estado
	//void setEstado(ID id);

	//Metodo para retornar o estado
	//ID getEstado();

	void Executar();
};

