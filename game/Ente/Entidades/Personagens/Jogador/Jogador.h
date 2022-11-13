#pragma once
#include "Ente/Entidades/Personagens/Personagens.h"
#include <time.h>


class Jogador :
    public Personagens
{
private:
    //atributo especificos (?)
    
    sf::Texture tex_jogador;
    sf::Sprite sprite_jogador;
    void iniciar();

public:
    Jogador();
    ~Jogador();

    void andar(int i);
 
    virtual void Mover();
    virtual void Executar();
    virtual void Colisao(Entidade* entidade);

};

