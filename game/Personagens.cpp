#include "Personagens.h"

Personagens::Personagens(const int vida, const int dano)
{
    /* NAO SEI SE PRECISA */
    this->vida = vida;
    this->dano = dano;
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
