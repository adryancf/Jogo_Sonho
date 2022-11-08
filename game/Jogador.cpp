#include "Jogador.h"

Jogador::Jogador():Personagens()
{
    q_vida = 3;
    ID = 1;
    
}

Jogador::Jogador(GerenciadorGrafico* pG)
{
    q_vida = 3;
    pGrafico = pG;
    ID = 1;
}


Jogador::~Jogador(){}

void Jogador::andar(int i)
{
    
    std::cout << "Posicao em x:" << corpo.getPosition().x << endl;
    std::cout << "Posicao em y:" << corpo.getPosition().y << endl;
    
    verificaPodeAndar();

    if (i == 2 && podeAndarEsquerda)
    {
        corpo.move(Vector2f(-speed.x, 0));
    }
    else if (i == 4 && podeAndarDireita)
    {
        corpo.move(Vector2f(speed.x, 0));
    }
  
}


void Jogador::Mover()
{
   
}

void Jogador::Executar()
{
    Mover();
}

void Jogador::Colisao(Entidade* entidade)
{
    std::cout << "COLIDIU" << endl;

    //Se for com inimigo
    if (entidade->getId() == 2)
    {
        Personagens* Inimigo = static_cast<Personagens*>(entidade);
        float df = verificaFuturoMov(Vector2f(-50.f, 0.f));
        //Se enconstar no inimigo o jogador vai para tras
        if (podeAndarEsquerda) {
            corpo.move(Vector2f(-50.0f, 0.0f));
            Inimigo->movimentarPersonagem(Vector2f(50.f, 0.f));
        }
        else
            corpo.move(Vector2f(-50.0f + df, 0.0f));
            Inimigo->movimentarPersonagem(Vector2f(50.f, 0.f));
    }

    //Se for com plataforma
    else if (entidade->getId() == 3)
    {


    }

    else if (entidade->getId() == 4)
    {

    }
}


