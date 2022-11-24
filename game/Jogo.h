#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "GerenciadorEventos.h"

using namespace std;
using namespace sf;

class Jogo: public Ente
{
private:
	Jogador* Jogador1;
	GerenciadorEvento* pEvento;

	Fase1* fase1;
	Fase2* fase2;

	//teste de background
	//sf::Texture textura;
	//sf::RectangleShape Corpo;

public:
	Jogo();
	~Jogo();

	void controleFases();

	void iniciaFase1();
	void deletaFase1();
	void iniciaFase2();
	void deletaFase2();

	void Executar();
};

