#include "Personagens.h"

Personagens::Personagens(const int vida, const int dano, Vector2f velocidade): podeAndarDireita(true), podeAndarEsquerda(true)
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

void Personagens::movimentarPersonagem(Vector2f mov)
{
    corpo.move(mov);
}

const int Personagens::getVida() const
{
    return vida;
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

float Personagens::verificaFuturoMov(Vector2f mov)
{
    //verifica se não está na borda
    Vector2f pos_personagem = corpo.getPosition();
    if (pos_personagem.x + mov.x <= 0.0f) {
        podeAndarEsquerda = false;
        podeAndarDireita = true;
        return ((pos_personagem.x + mov.x) * -1.0f);
    }
    else if (pos_personagem.x + mov.x >= BORDA_X) {
        podeAndarDireita = false;
        podeAndarEsquerda = true;
    }
    else {
        podeAndarDireita = true;
        podeAndarEsquerda = true;
    }


}

