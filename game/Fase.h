#pragma once

//REVISAR INCLUDES

#include "Hydra.h"
#include "Jogador.h"
#include "Fantasma.h"
#include "Anjo.h"
#include "Plataforma.h"
#include "Caixa.h"
#include "Espinho.h" //inclui personagem
#include "ListaEntidades.h"

#include "GerenciadorColisoes.h"


class Fase: virtual public Ente
{
protected:

	//Entidades
	Jogador* j1;
	Jogador* j2;

	Hydra* hydra;
	Plataforma* plataforma_fase;
	Caixa* caixa;

	//Lista
	ListaEntidades* lista_personagem;
	ListaEntidades* lista_obstaculos;

	//Colisoes
	GerenciadorColisoes* pColisoes;

	//Controle e inicializa��o
	unsigned int numero_instancias;
	bool ativa;
	virtual void criar_entidades() = 0;

	//Background
	RectangleShape fundo;
	Texture img_fundo;

	//Tempo do Jogo
	sf::Clock relogio_fase;
	float tempo_fase;



public:
	Fase(Jogador *j1, Jogador* j2);
	~Fase();

	const float tempoFase();

	//Background
	void setFundo(string path_fundo);
	void setFundo(string path_fundo, IntRect rect);

	//Features
	int gerarNumeroAleatorio(int min, int max);
	int gerarNumeroAleatorio(float min, float max);

	//Controle da EXECUCAO da fase
	void verificaTerminoFase();
	const bool getAtiva();

	void pontuacaoJogador();
	virtual void Executar() = 0;

	//Listas
	virtual void criarLista();
	void deletaListas();
	ListaEntidades* getListaPersonagem();
	ListaEntidades* getListaObstaculo();

	//Todas as fases vao ter esses elementos
	virtual void criarCaixa() = 0;
	virtual void criarPlataforma() = 0;
	virtual void criarHydra() = 0;

};

