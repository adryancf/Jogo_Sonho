#include "Personagens.h"

Personagens::Personagens(const int q_vida) :
    Entidade(),
    podeAndarDireita(true),
    podeAndarEsquerda(true),
    olhandoDireita(false),
    olhandoEsquerda(false),
    podePular(false),
    vivo(true),
    atacou(false),
    podeAndar(true),
    dano(0.0)
{
    this->q_vida = q_vida;
}

Personagens::~Personagens()
{
}

//ATAQUE

void Personagens::setDano(float dano)
{
    this->dano = dano;
}

const float Personagens::getDano() const
{
    return dano;
}

void Personagens::atacar(Personagens* adversario ,float dano)
{
    adversario->perdeVida();
}

void Personagens::setAtacou(bool ataque)
{
    atacou = ataque;

}

bool Personagens::getAtacou()
{
    return atacou;
}


// VIDA DO PERSONAGEM

void Personagens::setQuantidadeVida(float q)
{
    q_vida = q;
}

const float Personagens::getQuantidadeVida()
{
    return q_vida;
}

const bool Personagens::getVida() const
{
    return vivo;
}

void Personagens::verificaVida()
{
    if (q_vida <= 0) {
        vivo = false;

        //Tira ele do campo de visao para evitar colisoes indesejaveis
        setPosEntidade(Vector2f(-2000.f, -2000.f));
        gravidade = false;
    }
}

void Personagens::perdeVida()
{
    //DA PARA SUBSTITUIR POR UMA SOBRECARGA DE OPERADOR --
    if (vivo)
        q_vida--;
}

void Personagens::perdeVida(float dano)
{
    if (vivo)
        q_vida -= dano;
}

//MOVIMENTO E PULO

void Personagens::verificaPodeAndar()
{
    //verifica se nao esta na borda
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

void Personagens::verificaPodeAndar(Vector2f pos)
{
    //Verifica se o personagem pode andar no movimento que ele pretende fazer (FUTURO)

    Vector2f pos_personagem = corpo.getPosition();

    if (pos_personagem.x + pos.x <= 0.0f) {
        podeAndarEsquerda = false;
        podeAndarDireita = true;
    }
    else if (pos_personagem.x + pos.x >= BORDA_X) {
        podeAndarDireita = false;
        podeAndarEsquerda = true;
    }

    else {
        podeAndarDireita = true;
        podeAndarEsquerda = true;
    }
}

const Vector2<bool> Personagens::getPodeAndar()
{
    Vector2<bool> vetor_resposta;

    if (podeAndarDireita)
        vetor_resposta.x = true;
    else
        vetor_resposta.x = false;

    if (podeAndarEsquerda)
        vetor_resposta.y = true;
    else
        vetor_resposta.y = false;

    return vetor_resposta;
}

const Vector2<bool> Personagens::getOlhar()
{
    Vector2<bool> vetor_resposta;

    if (olhandoDireita)
        vetor_resposta.x = true;
    else
        vetor_resposta.x = false;

    if (olhandoEsquerda)
        vetor_resposta.y = true;
    else
        vetor_resposta.y = false;

    return vetor_resposta;
}

void Personagens::pular(double tam_pulo)
{
    if (noChao || emCima) {
        podePular = true;
    } else {
        podePular = false;
    }

    if (podePular)
    {
        //a alura do pulo vai ser determinada pela equação de torricelli
        speed.y = -sqrt(2.0 * GRAVIDADE * tam_pulo);
        noChao = false;
        emCima = false;
    }

}






