#include "Jogador.h"

int Jogador::pontuacao = 0;

Jogador::Jogador(int jogador):Personagens(), tempo()
{
    id = ID::jogador;
    iniciar();

    this->setTextura(jogador);


    //corpo.setSize(sf::Vector2f(70.0f, 70.0f));
}

void Jogador::iniciar()
{
    //Atributos Jogador
    corpo.setSize(Vector2f(JOGADOR_X, JOGADOR_Y));
    setVelocidade(Vector2f(VELOCIDADE_JOGADOR_X, 0.f));
    setQuantidadeVida(20.0);
    setDano(3.0);
}
Jogador::~Jogador(){}

void Jogador::setTextura(int i)
{
    if (i == 1)
    {
        sf::IntRect rect(59, 46, 30, 54);
        texture.loadFromFile("assets/Idle.png", rect);
        corpo.setTexture(&texture);

    }
    else if (i == 2)
    {
        sf::IntRect rect(59, 46, 30, 54);
        texture.loadFromFile("assets/Idle.png", rect);
        corpo.setTexture(&texture);
    }
}


void Jogador::atacar(Entidade* adversario, float dano)
{
    Personagens* adv = static_cast<Personagens*>(adversario);
    adv->perdeVida(dano);

    if (adv->getQuantidadeVida() <= 0.f)
        ganhaPontos();
}

void Jogador::Mover()
{
    movGravidade();

    if (andando)
    {
        if(olhandoDireita)
            movimentaEntidade(Vector2f(speed.x, 0.f), true);

        else if(olhandoEsquerda)
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);


    }
}

void Jogador::Executar()
{
    verificaVida();
    //cout << " Pontos Jogador: " << pontuacao << endl;
    Mover();

}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUN��ES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    andando = true;

    if (i == 2)
    {
        movimentaEntidade(Vector2f(-speed.x, 0.f), false);
    }
    else if (i == 4)
    {
        movimentaEntidade(Vector2f(speed.x, 0.f), true);
    }
}

void Jogador::verificaPontos(Entidade* inimigo)
{
    //SE O INIMIGO TA MORTO = PONTO
    if (inimigo->getVisivel() == false)
    {
        pontuacao++;
    }

}

void Jogador::ganhaPontos(int pontos)
{
    pontuacao = pontos;
}

void Jogador::ganhaPontos()
{
    ++pontuacao;
}

void Jogador::perdePontos(int pontos)
{
    pontuacao -= pontos;
}

void Jogador::perdePontos()
{
    pontuacao--;
}

const int Jogador::getPontos()
{
    return pontuacao;
}

//GERENCIADOR DE COLIS�ES
void Jogador::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);

}

/*
void Jogador::setTextura()
{
    textura->loadFromFile("assets/mushroom.PNG");
}
*/


