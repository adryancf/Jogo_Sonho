#pragma once
#include "Ente.h"

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

	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade) = 0;



};

