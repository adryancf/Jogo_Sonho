#pragma once
#include "Personagens.h"
class Inimigo :
    public Personagens
{
private:

public:
    Inimigo(const int v = 100, const int d = 10);
    ~Inimigo();

    virtual void Mover();
    virtual void Executar();
};

