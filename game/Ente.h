#pragma once
#include "GerenciadorGrafico.h"
#include "Id.h"

/* Jogo, Entidade, Fase */

class Ente
{
protected:
	//Todo ENTE deve conhecer a parte Gráfica do jogo (Janela - SFML)
	static GerenciadorGrafico* pGrafico;

	//Todo ente tem um ID
	ID id;

	//Todo ente tem uma posicao
	sf::Vector2f posicao;

	//Todo ente tem uma sprite (ou um retangulo)! SEM ANIMACAO, usando um RectangleShape mesmo que isso seja menos otimizado!
	sf::RectangleShape corpo;
	sf::Texture mTexture;


public:
	//Construtora/Destrutora
	//Construtora parametrizada
	Ente(ID id, sf::Vector2f pos);
	Ente();
	virtual ~Ente(); //eh importante que seja virtual pra nao haver conflito com as destrutoras das classes base

	//Define o Id
	void setId(ID idD);
	//Retorna o id
	const ID getId();

	//Retorna a posicao do ente
	const sf::Vector2f getPosicao();

	//Se o ente tem uma posicao ela pode ser alterada
	//Recebe um vetor e altera a posicao do ente para a posicao recebida
	void trocarPosicao(sf::Vector2f pos);

	//Recebe um vetor e adiciona as coordenadas x e y as coordenadas x e y recebidas
	void moverPosicao(sf::Vector2f pos);


	//Inicia a sprite e a textura, Ente eh abstrata
	virtual void initVariables() = 0;

	//Todo ente tem a capacidade de sofrer update sujeito a determinado tempo deltaTime
	virtual void update(float deltaTime) = 0;

	//Todo ente tem a capacidade de ser renderizado, simplesmente desenha o corpo
	virtual void render();
	
	//Retorna um ponteiro para o gerenciadorGrafico
	GerenciadorGrafico* getGrafico();
};

