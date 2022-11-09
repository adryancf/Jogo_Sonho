#include "Jogador.h"

Jogador::Jogador():Personagens()
{
    q_vida = 3;
    ID = 1;
}

Jogador::~Jogador(){}

void Jogador::Mover()
{
    movGravidade();
}

void Jogador::Executar()
{
    Mover();
}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUNÇÕES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    /* DEBUG */
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

//GERENCIADOR DE COLISÕES
void Jogador::Colisao(Entidade* entidade)
{
    //std::cout << "COLIDIU" << endl;

    verificaColisaoPlataforma(entidade);
    int id_entidade = entidade->getId();
    cout << id_entidade << endl;
    //Inimigo
    if (id_entidade == 2)
    {
        //Se enconstar no inimigo o jogador vai para tras
        if (podeAndarEsquerda) {
            corpo.move(Vector2f(-30.0f, 0.0f));
            entidade->movimentaEntidade(Vector2f(30.0f, 0.0f));
        }
        else {
            corpo.move(Vector2f(10.0f, 0.0f));
            entidade->movimentaEntidade(Vector2f(10.0f, 0.0f));
        }
    }

    
    
}


