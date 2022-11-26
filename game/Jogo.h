#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "GerenciadorEventos.h"
#include "Menu.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	Jogador* Jogador1;
	Jogador* Jogador2;

	static GerenciadorEvento* pEvento;

	//Controle de tempo
	sf::Clock clock_jogo;
	float tempo_jogo;


	Fase1* fase1;
	Fase2* fase2;
	Menu* menu;




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

