#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "GerenciadorEventos.h"

#include "MenuPrincipal.h"
#include "MenuJogadores.h"
#include "MenuPause.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	Jogador* Jogador1;
	Jogador* Jogador2;

	static GerenciadorEvento* pEvento;

	Fase1* fase1;
	Fase2* fase2;

	MenuPrincipal* menu;
	MenuJogadores* menuj;
	MenuPause* menup;

	//2: DOIS JOGADORES | 1: UM JOGADOR
	int qJogadores;


public:
	Jogo();
	~Jogo();

	void controleFases();

	void iniciaFase1();
	void deletaFase1();
	void iniciaFase2();
	void deletaFase2();

	void iniciarMenu();

	void Executar();
};

