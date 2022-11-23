#include "Caixa.h"

Caixa::Caixa() : fixa(true)
{
}

Caixa::Caixa(const sf::Vector2f tam, const sf::Vector2f pos, bool estado_caixa):
	fixa(estado_caixa)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(sf::Color::Red);
	id = ID::caixa;
}

Caixa::~Caixa()
{
}

void Caixa::setEstadoCaixa(bool estado_caixa)
{
	fixa = estado_caixa;
}

const bool Caixa::getEstadoCaixa()
{
	return fixa;
}


void Caixa::Executar()
{
	movGravidade();
}

void Caixa::atacar(Entidade* adversario, float dano)
{
}

void Caixa::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	if (fixa) {
		if (entidade->getId() == ID::plataforma || entidade->getId() == ID::caixa || entidade->getId() == ID::espinho)
			corrigeColisoes(entidade, inter_colisao);
	}
	else {
		if (verificarPosInvalida() || entidade->getId() == ID::caixa) {
			fixa = true;
			cout << "entrei" << endl;
		}
		else {
			if(entidade->getId() == ID::jogador || entidade->getId() == ID::plataforma)
				corrigeColisoes(entidade, inter_colisao);
		}
	}
}
