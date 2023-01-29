#pragma once
#include "Fase.h"

class Fase2: public Fase
{
private:

	//NESSA FASE VAI TER ESPECIFICAMENTE
	Ceifador* ceifador;
	Projetil* projetil_ceifador;
	Espinho* espinho;

	virtual void criar_entidades();

public:
	Fase2(Jogador* j1, Jogador* j2);
	~Fase2();

	//Personagem
	void criarCeifador();

	//Obstaculo
	void criaEspinhos();
	virtual void criarPlataforma();
	virtual void criarCaixa();
	virtual void criarHydra();


	virtual void Executar();
};

