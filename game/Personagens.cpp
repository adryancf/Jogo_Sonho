#include "Personagens.h"

Personagens::Personagens(const int q_vida, const int dano): 
    podeAndarDireita(true), 
    podeAndarEsquerda(true),
    olhandoDireita(false),
    olhandoEsquerda(false)
{
    this->dano = dano;
    this->q_vida = q_vida;
}

Personagens::~Personagens()
{
}


void Personagens::setVida(int q)
{
    this->q_vida = q;
}

const int Personagens::getVida() const
{
    return q_vida;
}

const int Personagens::getDano() const
{
    return dano;
}

void Personagens::verificaPodeAndar()
{
    //verifica se não está na borda
    Vector2f pos_personagem = corpo.getPosition();
    if (pos_personagem.x <= 0.0f) {
        podeAndarEsquerda = false;
        podeAndarDireita = true;
    }
    else if (pos_personagem.x >= BORDA_X) {
        podeAndarDireita = false;
        podeAndarEsquerda = true;
    }
 
    else {
        podeAndarDireita = true;
        podeAndarEsquerda = true;
    }
}






