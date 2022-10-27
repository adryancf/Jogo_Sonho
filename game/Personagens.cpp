#include "Personagens.h"

Personagens::Personagens()
{
    /* NAO SEI SE PRECISA */
    vida = 0;
    dano = 0;
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
