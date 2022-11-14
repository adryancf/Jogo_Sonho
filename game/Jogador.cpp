#include "Jogador.h"

void Jogador::iniciar()
{

}

Jogador::Jogador():Personagens()
{
    setVelocidade(Vector2f(10.f, 0.f));
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

    speed.x = 10.f;

    verificaPodeAndar();

    if (i == 2 && podeAndarEsquerda)
    {
        corpo.move(Vector2f(-speed.x, 0));
        olhandoEsquerda = true;
        olhandoDireita = false;
    }
    else if (i == 4 && podeAndarDireita)
    {
        corpo.move(Vector2f(speed.x, 0));
        olhandoDireita = true;
        olhandoEsquerda = false;
    }

}

//GERENCIADOR DE COLISÕES
void Jogador::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);
    verificaColisaoPlataforma(entidade);
    
    int id_entidade = entidade->getId();

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


