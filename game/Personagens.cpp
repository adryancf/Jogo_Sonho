#include "Personagens.h"

Personagens::Personagens(const int vida, const int dano, Vector2f velocidade)
{
    /* NAO SEI SE PRECISA */
    this->vida = vida;
    this->dano = dano;
    this->speed = velocidade;
    this->q_vida = 1;
}

Personagens::~Personagens()
{
}

const int Personagens::getVida() const
{
    return vida;
}

const int Personagens::getDano() const
{
    return dano;
}
