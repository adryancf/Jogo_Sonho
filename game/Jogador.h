#pragma once
#include "Personagens.h"
#include "Dragao.h"
#include <time.h>
#include "Obstaculo.h"


class Jogador :
    public Personagens
{
private:
    //atributo especificos (?)
    //Projetil/arma
    //Futuramente uma sprite
    sf::Texture tex_jogador;
    sf::Sprite sprite_jogador;
    sf::Clock tempo;
    void iniciar();
    
public:
    Jogador();
    ~Jogador();

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    void initVariables();

    void andar(int i);
 
    virtual void Mover();
    virtual void Executar();

    //O jogador não está colidindo apropriadamente com a plataforma (?)
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);
};

