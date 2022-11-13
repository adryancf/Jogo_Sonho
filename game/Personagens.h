#pragma once
#include "Entidade.h"

class Personagens :
    public Entidade
{
protected:

    //Qual a diferença entre vida e q_vida?
    //Acho que vida é inútil neste contexto
    //int vida;
    //Acho que dano é inútil neste contexto
    //int dano;
    int q_vida;

    //Ideia para considerar quantidade de vidas: CRIAR uma classe vida, que contem o valor da vida. 

    sf::Vector2f speed;

    bool podeAndarDireita;
    bool podeAndarEsquerda;


public:
    //Por padrão personagens tem 1 vida
    Personagens(const int vida = 1, /*const int dano = 10,*/ Vector2f velocidade = Vector2f(5.0f, 0.0f));
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
    //Cada personagem atualiza a vida a sua maneira
    virtual void atualizarVida() = 0;
};

