
#include "Inimigo.h"


Inimigo::Inimigo():Personagens(3), tempo_inimigos()
{   
    movRandom = rand() % 4; //SEED FALTANTE
    id = ID::inimigo; // ARRUMAR ID
}


Inimigo::~Inimigo()
{
}


void Inimigo::movAleatorio()
{
    verificaPodeAndar(speed);

    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 0.1s */
    if (noChao) {
        if (movRandom == 1 && podeAndarDireita) {
            movimentaEntidade(Vector2f(speed.x, 0.f), true);
        }
        else if (movRandom == 2 && podeAndarEsquerda) {
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);
        }
    }
    
    float dt = tempo_inimigos.getElapsedTime().asSeconds();
    if (dt >= 0.5f) {
        movRandom = rand() % 4;
        tempo_inimigos.restart();
    }

}

