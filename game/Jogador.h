#pragma once
#include "Personagens.h"

class Jogador :
    public Personagens
{
private:
    
public:
    Jogador(const int v = 100, const int d = 10);
    ~Jogador();
    
    virtual void Mover();
    virtual void Executar();

};

