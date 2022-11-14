#pragma once
#include <cmath>
#include "Jogador.h"


#define RAIO_X 150.0f
#define RAIO_Y 150.0f

//Depois devemos adicionar um virtual antes do public
//Esta classe deve ser virtual pura
//Não vou alterar agora pq modifica o funcionamento da Fase (que também deve ser alterada)
class Inimigo :
    public Personagens
{
private:
    Jogador* jogador;
    sf::Clock time;
    int movRandom;

    //Futuramente uma sprite
    //sf::Texture j_textura;
    //sf::Sprite j_sprite;

public:
    Inimigo(Jogador* j);
    ~Inimigo();
    
    /* O Inimigo seguira o jogador a partir do momento q ele entrar na rand do inimigo. Caso o Jogador esteja longe, o inimo se movimentara aleatoriamente */

    //JOGADOR ESTA NA RAND
    void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);
    
    //JOGADOR FORA DA RAND
    void movAleatorio();
           
    //Quando colocar o virtual antes do public esses m�todos devem ser comentados
    virtual void Mover();
    virtual void Executar();
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    //void initVariables();
};

