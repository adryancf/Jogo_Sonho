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
    movGravidade();
}

void Jogador::Executar()
{
    Mover();
    if (colisao == false)
        gravidade = true;
}

void Jogador::Colisao(Entidade* entidade)
{
    std::cout << "COLIDIU" << endl;

    //Se for com inimigo
    if (entidade->getId() == 2)
    {
        Personagens* Inimigo = static_cast<Personagens*>(entidade);
        //Se enconstar no inimigo o jogador vai para tras
        if (podeAndarEsquerda) {
            corpo.move(Vector2f(-50.0f, 0.0f));
            Inimigo->movimentarPersonagem(Vector2f(50.f, 0.f));
        }
        else
            corpo.move(Vector2f(-50.0f, 0.0f));
            Inimigo->movimentarPersonagem(Vector2f(50.f, 0.f));
    }

    if (entidade->getId() == 3)
    {
        gravidade = false;
        noChao = true;
    }

    
}


