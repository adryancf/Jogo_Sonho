#pragma once

#include "Jogador.h"

class Inimigo : public Personagens
{
private:
    sf::Clock tempo_mov;
    int movRandom;

protected:
    Vector2f raio_deteccao;
    Jogador* player;

    bool jogadorEmCima;

    /* Futuramente uma sprite */

    //sf::Texture j_textura;
    //sf::Sprite j_sprite;

public:
    Inimigo();
    ~Inimigo();
    
    //Movimentos
    void movAleatorio();
    void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);
    void podePerseguir(Personagens* personagem);

           
    virtual void Mover() = 0;
    virtual void Executar() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    //void initVariables();
};

