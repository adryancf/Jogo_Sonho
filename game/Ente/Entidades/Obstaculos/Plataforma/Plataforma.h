#pragma once
#include "Ente/Entidades/Obstaculos/Obstaculo.h"

class Plataforma :
    public Obstaculo
{

private:


public:
    Plataforma(Vector2f tam, Vector2f pos);
    Plataforma();
    ~Plataforma();

    virtual void Executar();
    virtual void Colisao(Entidade* entidade);
};

