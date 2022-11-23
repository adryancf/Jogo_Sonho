#pragma once
#include "Fase.h"

class Fase2: public Fase
{
private:

	//NESSA FASE VAI TER ESPECIFICAMENTE
	Anjo* anjo;
	Projetil* projetil_anjo;

	virtual void criar_entidades();

public:
	Fase2(Jogador* j1);
	~Fase2();

	//Personagem
	void criarAnjo();

	//Obstaculo
	virtual void criarPlataforma();
	virtual void criarCaixa();
	virtual void criarHydra();


	virtual void Executar();
};

