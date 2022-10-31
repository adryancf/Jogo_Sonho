#pragma once
#include "Entidade.h"


class Personagens :
    public Entidade
{
protected:
    //Acho que nao precisa do nome nos personagens
    string nome;
    int vida; //PODE TER MAIS DE UMA VIDA (?)
    int dano;

public:
    Personagens(const int vida = 100, const int dano = 10);
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

    //metodo -> atualizar vida (implementar)
};

