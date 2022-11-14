
#include "Inimigo.h"


Inimigo::Inimigo(Jogador* j):Personagens()
{

    setVelocidade(Vector2f(1.0f, 0.0f));

    corpo.setPosition(Vector2f(500.f, 150.f));
    jogador = j;
    movRandom = rand() % 4; //SEED FALTANTE
    ID = 2; // ARRUMAR ID
}


Inimigo::~Inimigo()
{
}

//O inimigo eh abstrata! Cada mob deve ter sua propria funcao mover!
//dps de adicionar o virtual devemos comentar
void Inimigo::Mover()
{
    //Aplica a gravidade
    movGravidade();

    Vector2f posJogador = jogador->getCorpo().getPosition();
    Vector2f posInimigo = corpo.getPosition();

    //fun��o fabs : MODULO DA DIFEREN�A
    
    //Isso so vai acontecer se o jogador bater pela primeira vez no inimigo -> IMPLEMENTAR MAIS PRA FRENTE
    //VERIFICA SE O JOGADOR ESTA NO RAIO DE DETEC��O
    if ((fabs(posJogador.x - posInimigo.x) <= RAIO_X) && (fabs(posJogador.y - posInimigo.y) <= RAIO_Y)) {
        PersegueJogador(posJogador, posInimigo);
    }
    else
        movAleatorio();
}

void Inimigo::PersegueJogador(Vector2f posJogador, Vector2f posInimigo)
{
    verificaPodeAndar();

    /*
    //Jogador direita = Inimigo para direita
    if ((posJogador.x - posInimigo.x) > 0.0f && podeAndarDireita) { corpo.move(speed.x, 0.0f); }
    //Jogador esquerda = Inimigo para esquerda
    else if(podeAndarEsquerda) { corpo.move(-speed.x, 0.0f); }
    */
}

void Inimigo::movAleatorio()
{
    verificaPodeAndar();

    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 1s */
    if (noChao) {
        if (movRandom == 1 && podeAndarDireita)
            corpo.move(speed.x, 0.f);
        else if (movRandom == 2 && podeAndarEsquerda)
            corpo.move(-speed.x, 0.f);
    }
  
    float dt = time.getElapsedTime().asSeconds();
    if (dt >= 0.2f) {
        movRandom = rand() % 4;
        time.restart();
    }
}


//dps de adicionar o virtual devemos comentar
void Inimigo::Executar()
{
    Mover();
}

//dps de adicionar o virtual devemos comentar
void Inimigo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);
    verificaColisaoPlataforma(entidade);
}
