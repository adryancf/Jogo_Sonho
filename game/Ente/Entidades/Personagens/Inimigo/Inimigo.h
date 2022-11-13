#pragma once
#include <cmath>
#include "Ente/Entidades/Personagens/Jogador/Jogador.h"


#define RAIO_X 150.0f
#define RAIO_Y 150.0f

//Depois devemos adicionar um virtual antes do public
class Inimigo : public Personagens
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
           
    //Quando colocar o virtual antes do public esses métodos devem ser comentados
    virtual void Mover();
    virtual void Executar();
    virtual void Colisao(Entidade* entidade);
    
};

