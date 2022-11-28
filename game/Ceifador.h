#pragma once

#include "Inimigo.h"
#include "Projetil.h"

class Ceifador: public Inimigo
{
private:
	//Crio o projetil na fase, pois precico inclui-lo na lista de personagens
	Projetil* projetil;

	Personagens* alvo;
	Vector2f posAlvo;

	float tempo_atk;

	//Controle
	string direcao_alvo;

public:
	Ceifador(Jogador* p1, Jogador* p2, Projetil* b);
	~Ceifador();

	void setAlvo(Personagens* alvo);
	const Personagens* getAlvo() const;
	void EncontraPosAlvo();


	const Projetil* getProjetil();
	virtual void atirar_projetil();

	void inicializaVariaveis();

	virtual void Mover();
	virtual void Executar();
	virtual void reagirColisao(Entidade* entidade, Vector2f inter_colisao);
};

