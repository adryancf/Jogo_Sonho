#pragma once
#include "Entidade.h"

class Jogador :
    public Entidade
{
private:
    string nome;

public:
    Jogador();
    ~Jogador();
    
    void mover();
    virtual void Executar();

    void setName(const string a);
    const string getName() const;
};

