#pragma once
#include "Personagens.h"
#include <time.h>


class Jogador :
    public Personagens
{
private:
    //atributo especificos (?)
    //Projetil/arma

public:
    Jogador();
    ~Jogador();

    void andar(int i);
 
    virtual void Mover();
    virtual void Executar();
    virtual void Colisao(Entidade* entidade);

};

