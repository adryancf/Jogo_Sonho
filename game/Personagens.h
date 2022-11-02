#pragma once
#include "Entidade.h"


class Personagens :
    public Entidade
{
protected:

    int vida;
    int dano;
    int q_vida;

    //Ideia para considerar quantidade de vidas: CRIAR uma classe vida, que contem o valor da vida. 

    sf::Vector2f speed;

public:
    Personagens(const int vida = 100, const int dano = 10, Vector2f velocidade = Vector2f(10.0f, 10.0f));
    ~Personagens();

    /* Nao precicso de set pois inicializo os argumentos na construtora da classe herdada */

    //void setVida();
    const int getVida() const;

    //void setDano();
    const int getDano() const;

    virtual void Executar() = 0;
    virtual void Mover() = 0;

    //metodo -> atualizar vida (implementar)
};

