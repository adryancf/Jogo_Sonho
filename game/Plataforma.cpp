#include "Plataforma.h"

Plataforma::Plataforma(const Vector2f tam, const Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	//corpo.setFillColor(Color::Green);

	id = ID::plataforma;
	texture.loadFromFile("assets/brownPlatform.png");
	corpo.setTexture(&texture);

}

Plataforma::Plataforma()
{
	id = ID::plataforma;
}

Plataforma::~Plataforma()
{
}

void Plataforma::Executar()
{
	movGravidade();
	anulaGravidade();
}

void Plataforma::atacar(Entidade* adversario, float dano)
{
}

void Plataforma::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
}
