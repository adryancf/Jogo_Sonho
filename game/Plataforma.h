#pragma once
#include "Obstaculo.h"
class Plataforma :
    public Obstaculo
{

private:
    sf::Texture texture;

public:
    Plataforma(Vector2f tam, Vector2f pos);
    Plataforma();
    ~Plataforma();

    virtual void atacar(Entidade* adversario, float dano);
    virtual void Executar();
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);
};

