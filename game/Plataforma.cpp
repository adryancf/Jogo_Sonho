#include "Plataforma.h"

Plataforma::Plataforma(const Vector2f tam, const Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(Color::Green);

	ID = 3; //Alterar

}

Plataforma::Plataforma()
{
	ID = 3;
}

Plataforma::~Plataforma()
{
}

void Plataforma::Executar()
{
	movGravidade();
	anulaGravidade();
}

void Plataforma::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}
