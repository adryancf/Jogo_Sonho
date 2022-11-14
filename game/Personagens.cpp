#include "Personagens.h"

Personagens::Personagens(const int qvida): 
    podeAndarDireita(true), 
    podeAndarEsquerda(true),
    olhandoDireita(false),
    olhandoEsquerda(false)
{
    this->q_vida = qvida;
}

Personagens::~Personagens()
{
}

/*
* Funcoes descenessarias
*/ 
void Personagens::setVida(int q)
{
    q_vida = q;
}

const int Personagens::getVida() const
{
    return q_vida;
}


void Personagens::verificaPodeAndar()
{
    //verifica se n�o est� na borda
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






