#pragma once

#include "Personagens.h"

//Depois devemos adicionar um virtual antes do public
//Esta classe deve ser virtual pura
//Não vou alterar agora pq modifica o funcionamento da Fase (que também deve ser alterada)
class Inimigo :
    public Personagens
{
protected:
    sf::Clock tempo_inimigos;
    int movRandom;

    /* Futuramente uma sprite */

    //sf::Texture j_textura;
    //sf::Sprite j_sprite;

public:
    Inimigo();
    ~Inimigo();
    
    //Movimentos
    void movAleatorio();
           
    virtual void Mover() = 0;
    virtual void Executar() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    //void initVariables();
};

