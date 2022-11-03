
#include "../../Projeto_Jogo/game/Inimigo.h"


Inimigo::Inimigo(Jogador* j):Personagens(50, 20, Vector2f(1.f, 1.f))
{
    corpo.setPosition(Vector2f(800.0f, 500.0f));
    corpo.setFillColor(Color::Blue);
    jogador = j;
    movRandom = rand() % 4;
}


Inimigo::~Inimigo()
{
}

void Inimigo::Mover()
{

    //Pego a posição do Jogador
    Vector2f posJogador = jogador->getCorpo().getPosition();

    //Pego a posição do inimigo
    Vector2f posInimigo = corpo.getPosition();

    /* função fabs : MODULO DA DIFERENÇA */

    //VERIFICA SE O JOGADOR ESTA NO RAIO DE DETECÇÃO
    if ((fabs(posJogador.x - posInimigo.x) <= RAIO_X) && (fabs(posJogador.y - posInimigo.y) <= RAIO_Y)) {
        PersegueJogador(posJogador, posInimigo);
    }
    else
        movAleatorio();


}

void Inimigo::PersegueJogador(Vector2f posJogador, Vector2f posInimigo)
{
    //Jogador direita = Inimigo para direita
    if ((posJogador.x - posInimigo.x) > 0.0f) { corpo.move(speed.x, 0.0f); }

    //Jogador esquerda = Inimigo para esquerda
    else{ corpo.move(-speed.x, 0.0f); }

    

    /* Essa parte acho q da para tirar depois, devido ao pulo | NAO QUERO Q O INIMIGO IMITE MEUS PULOS, POIS TORNA MT DIFICIL DE DESVIAR */

    //Jogador cima = inimigo para cima
    //if ((posJogador.y - posInimigo.y) > 0.0f) { corpo.move(0.0f, speed.y); }

    //Jogador baixo = Inimigo para baixo
    //else { corpo.move(0.0f, -speed.y); }
    
}

void Inimigo::movAleatorio()
{
    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 1s */

    if (movRandom == 1)
        corpo.move(speed.x, 0.f);
    else if (movRandom == 2)
        corpo.move(-speed.x, 0.f);
    /*
    else if (movRandom == 3)
        corpo.move(0.f, speed.y);
    else
        corpo.move(0.f, -speed.y);
    */
    float dt = time.getElapsedTime().asSeconds();
    if (dt >= 0.6f) {
        movRandom = rand() % 4;
        time.restart();
    }
}



void Inimigo::Executar()
{
    Mover();
}
