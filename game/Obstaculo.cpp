#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::anulaGravidade()
{
	if (gravidade) {

		float vetor_contrario = speed.y * -1.0;
		corpo.move(Vector2f(0.0f, vetor_contrario));
	}

}
