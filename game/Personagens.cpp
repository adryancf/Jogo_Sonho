#include "Personagens.h"

Personagens::Personagens(const int q_vida):
    Entidade(),
    podeAndarDireita(true), 
    podeAndarEsquerda(true),
    olhandoDireita(false),
    olhandoEsquerda(false),
    vivo(true),
    atacou(false)
{
    this->q_vida = q_vida;
}

Personagens::~Personagens()
{
}

void Personagens::setAtacou(bool ataque)
{
    atacou = ataque;

}

bool Personagens::getAtacou()
{
    return atacou;
}

void Personagens::setQuantidadeVida(int q)
{
    q_vida = q;
}

const int Personagens::getQuantidadeVida()
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

const Vector2i Personagens::getOlhar()
{
    Vector2i vetor_resposta;

    if (olhandoDireita)
        vetor_resposta.x = 1;
    else
        vetor_resposta.x = 0;

    if (olhandoEsquerda)
        vetor_resposta.y = 1;
    else
        vetor_resposta.y = 0;

    return vetor_resposta;
}

void Personagens::perdeVida()
{
    if(vivo)
        q_vida--;
}


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
    //verifica se nao esta na borda
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

void Personagens::pular(double tam_pulo)
{
    if (noChao)
    {
        //a alura do pulo vai ser determinada pela equação de torricelli
        speed.y = -sqrt(2.0 * GRAVIDADE * tam_pulo);
        noChao = false;
    }

}






