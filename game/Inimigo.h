#pragma once
#include <cmath>
#include <time.h>
#include "Jogador.h"


#define RAIO_X 200.0f
#define RAIO_Y 200.0f

class Inimigo :
    public Personagens
{
private:
    Jogador* jogador;
    sf::Clock time;
    int movRandom;

public:
    Inimigo(Jogador* j);
    ~Inimigo();
    
    /* O Inimigo seguira o jogador a partir do momento q ele entrar na rand do inimigo. Caso o Jogador esteja longe, o inimo se movimentara aleatoriamente */

    //JOGADOR ESTA NA RAND
    void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);
    
    //JOGADOR FORA DA RAND
    void movAleatorio();
            
    virtual void Mover();
    virtual void Executar();
};

