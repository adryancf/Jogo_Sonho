#pragma once

#include "Inimigo.h"
#include "Projetil.h"

class Anjo: public Inimigo
{
private:
	//Crio o projetil na fase, pois precico inclui-lo na lista de personagens
	Projetil* projetil;

public:
	Anjo(Jogador* p);
	Anjo(Personagens* alvo);
	~Anjo();

	const Projetil* getProjetil();

	void inicializa();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

