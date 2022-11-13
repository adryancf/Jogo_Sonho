#pragma once
#include "Personagens.h"
#include <time.h>


class Jogador :
    public Personagens
{
private:
    //atributo especificos (?)
    //Projetil/arma
    //Futuramente uma sprite
    //sf::Texture j_textura;
    //sf::Sprite j_sprite;

public:
    Jogador();
    ~Jogador();

    void andar(int i);
 
    virtual void Mover();
    virtual void Executar();

    //O jogador não está colidindo apropriadamente com a plataforma
    virtual void Colisao(Entidade* entidade);

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    //void initVariables();

};

