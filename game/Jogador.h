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

    //alterar (colocar esse parâmetro na entidade)
    Jogador(GerenciadorGrafico* pG);


    ~Jogador();

    void andar(int i);
 
    virtual void Mover();
    virtual void Executar();
    virtual void Colisao(Entidade* entidade);

};

