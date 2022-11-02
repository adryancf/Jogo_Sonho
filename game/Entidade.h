#pragma once
#include "Ente.h"

//:pulic sf::Drawable (?)
class Entidade : public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;

public:
	Entidade();
	
	//PODE SER DESTRUTORA VIRTUAL PURA?
	~Entidade();

	//Retorna o shape da entidade
	RectangleShape getCorpo();
	
	virtual void Executar() = 0;

};

