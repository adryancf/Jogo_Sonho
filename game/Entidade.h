#pragma once
#include "Ente.h"

#define BORDA_X 1210.0
#define BORDA_Y 650.0

#define GRAVIDADE 1.0f

//:pulic sf::Drawable (?)
class Entidade : public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;
 
	int ID;

	bool colisao;
	bool gravidade;
	bool noChao;

public:
	Entidade();
	~Entidade();

	//CORPO
	RectangleShape getCorpo();
	void setColor(sf::Color cor);
	void setPosEntidade(Vector2f pos);
	void movimentaEntidade(Vector2f mov);
	const int getId();

	//COLISAO E GRAVIDADE
	void setColisao(bool a);
	void movGravidade();
	void verificaColisaoPlataforma(Entidade* e);
	
	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade) = 0;



};

