#pragma once
#include "Fase.h"

class Fase1: public Fase
{
private:

	//NESSA FASE VAI TER ESPECIFICAMENTE
	Dragao* dragao;
	Hydra* hydra;

	virtual void criar_entidades();

public:
	Fase1(Jogador* j1);
	~Fase1();

	//Personagem
	void criarDragao();
	void criarHydra();

	//Obstaculo
	virtual void criarPlataforma();
	virtual void criarCaixa();

	virtual void Executar();


};

