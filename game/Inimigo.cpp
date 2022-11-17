
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
            olhandoDireita = true;
            olhandoEsquerda = false;
            corpo.move(speed.x, 0.f);
        }
        else if (movRandom == 2 && podeAndarEsquerda) {
            olhandoEsquerda = true;
            olhandoDireita = false;
            corpo.move(-speed.x, 0.f);
        }
    }
    
    float dt = tempo_inimigos.getElapsedTime().asSeconds();
    if (dt >= 0.5f) {
        movRandom = rand() % 4;
        tempo_inimigos.restart();
    }

}


//Nao vamos tratar colisoes entre persoganes inicialmente
//Sendo assim, nao precisa cada inimigo redefinir sua colisao, pois ela so vai ser chamada quando se colide com a plataforma
void Inimigo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);
}
