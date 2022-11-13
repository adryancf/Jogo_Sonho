#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"


/*  GERENCIA TODOS OS EVENTOS DO JOGO  */
/*									   */
/*     PADRAO DE PROJETO SINGLETON     */


class GerenciadorEvento
{
private:
	GerenciadorGrafico* pGrafico;
	Jogador* Jogador1;

	int tecla_pres;
	
	static GerenciadorEvento* pEvento;
	GerenciadorEvento();


public:
	~GerenciadorEvento();

	static GerenciadorEvento* getGerenciadorEvento();
	void setJogador(Jogador* j);
	void verificaTeclaPressionada(sf::Keyboard::Key tecla);
	void verificaTeclaSolta(sf::Keyboard::Key tecla);
	void Executar();




};

