#include "Entidade.h"

#define GRAVIDADE 99.8f

Entidade::Entidade(): corpo(Vector2f(70.f, 70.f)), Ente(), colisao(false), gravidade(true), noChao(false)
{
    //Posicao padrao de todas as entidades
    corpo.setPosition(Vector2f(200.f, 500.f));
    ID = 0;
}


Entidade::~Entidade(){}

RectangleShape Entidade::getCorpo(){ return corpo; }

void Entidade::setColor(sf::Color cor)
{
    corpo.setFillColor(cor);
}

const int Entidade::getId()
{
    return ID;
}

void Entidade::setColisao(bool a)
{
    colisao = a;
}

void Entidade::movGravidade()
{
    if (colisao == false)
        gravidade = true;

    if (gravidade) {
        //formula da gravidade
        float velocidade = 0;
        velocidade += (GRAVIDADE * GerenciadorGrafico::dt);
        corpo.move(Vector2f(0.0f, velocidade));
        std::cout << velocidade << endl;
    }
}

void Entidade::verificaColisaoPlataforma(Entidade* e)
{
    //Plataforma
    if (e->getId() == 3)
    {
        gravidade = false;
        noChao = true;
    }
}

void Entidade::setPosEntidade(Vector2f pos)
{
    corpo.setPosition(pos);
}

void Entidade::movimentaEntidade(Vector2f mov)
{
    corpo.move(mov);
}


