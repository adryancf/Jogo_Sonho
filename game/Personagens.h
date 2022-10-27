#pragma once
#include "Entidade.h"


class Personagens :
    public Entidade
{
protected:
    string nome;
    int vida;
    int dano;

public:
    Personagens();
    ~Personagens();

    /* Nao precicso de set pois inicializo os argumentos na construtora da classe herdada */

    //void setVida();
    const int getVida() const;

    //void setDano();
    const int getDano() const;

    void setNome(const string s);
    const string getNome() const;

    virtual void Executar() = 0;
    virtual void Mover() = 0;

};

