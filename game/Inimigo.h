#pragma once
#include "Personagens.h"
class Inimigo :
    public Personagens
{
private:

public:
    Inimigo();
    ~Inimigo();

    virtual void Mover();
    virtual void Executar();
};

