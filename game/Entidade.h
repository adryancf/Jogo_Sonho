#pragma once
#include "Ente.h"

#define BORDA_X 1210.0
#define BORDA_Y 650.0

//:pulic sf::Drawable (?)
class Entidade : public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;
	int ID;


public:
	Entidade();
	
	//PODE SER DESTRUTORA VIRTUAL PURA?
	~Entidade();

	//Retorna o shape da entidade
	RectangleShape getCorpo();
	const int getId();

	void setPosEntidade(Vector2f pos);
	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade) = 0;



};

