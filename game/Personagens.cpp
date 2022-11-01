#include "Personagens.h"

Personagens::Personagens(Vector2f pos, const int vida, const int dano, Vector2f velocidade)
{
    /* NAO SEI SE PRECISA */
    this->vida = vida;
    this->dano = dano;
    this->speed = velocidade;
    this->q_vida = 1;
    corpo.setPosition(pos);
}

Personagens::~Personagens()
{
}

void Personagens::setNome(const string s)
{
    nome = s;
}

const string Personagens::getNome() const
{
    return nome;
}

const int Personagens::getVida() const
{
    return vida;
}

const int Personagens::getDano() const
{
    return dano;
}
