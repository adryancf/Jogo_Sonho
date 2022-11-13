#pragma once
#include "Ente/Entidades/Entidade.h"

class Personagens : public Entidade
{
protected:

    int vida;
    int dano;
    int q_vida;

    //Ideia para considerar quantidade de vidas: CRIAR uma classe vida, que contem o valor da vida. 

    sf::Vector2f speed;

    bool podeAndarDireita;
    bool podeAndarEsquerda;


public:
    Personagens(const int vida = 100, const int dano = 10, Vector2f velocidade = Vector2f(5.0f, 0.0f));
    ~Personagens();

    //void setVida();
    const int getVida() const;

    //void setDano();
    const int getDano() const;

    //Verifica se o Personagem pode Andar
    void verificaPodeAndar();
   
    virtual void Executar() = 0;
    virtual void Mover() = 0;
    virtual void Colisao(Entidade* entidade) = 0;

    //metodo -> atualizar vida (implementar)
};

