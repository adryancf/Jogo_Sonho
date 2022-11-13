#include "Jogador.h"

//O jogador é um personagem e tem 3 vidas
Jogador::Jogador() : Personagens(3)
{
    //q_vida = 3;
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
//Pq vc usou um inteiro como parâmetro?
//Não seria melhor utilizar o sf::Kyeboard::isKeyPressed(sf::Keyboard::A), por exemplo?
void Jogador::andar(int i) //Talvez seja melhor dar outro nome para esse método, ex: atualizaMovemento
{
    //DEBUG
    std::cout << "Posicao em x:" << corpo.getPosition().x << endl;
    std::cout << "Posicao em y:" << corpo.getPosition().y << endl;

    verificaPodeAndar();
    //a princípio não está se movendo
    //this->isMoving = false;
    if (i == 2 && podeAndarEsquerda)
    {
        corpo.move(Vector2f(-speed.x, 0.f));
        //att o isMoving
        //this->moving = true;
    }
    else if (i == 4 && podeAndarDireita)
    {
        corpo.move(Vector2f(speed.x, 0.f));
        //att o isMoving
        //this->moving = true;
    }

}

//GERENCIADOR DE COLISÕES
//Recebe uma entidade como parâmetro e verifica se ela colidindo
void Jogador::Colisao(Entidade* entidade)
{
    //std::cout << "COLIDIU" << endl;

    verificaColisaoPlataforma(entidade);
    int id_entidade = entidade->getId();
    cout << id_entidade << endl;
    //Inimigo
    //Esse método com ids não é legal
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


