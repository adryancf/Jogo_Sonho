#pragma once
#include "Entidade.h"
class Obstaculo :
    public Entidade
{
protected:


public:
    Obstaculo();
    ~Obstaculo();



    virtual void Executar() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;



};

