#include "Entidade.h"


Entidade::Entidade(): corpo(Vector2f(70.f, 70.f)), Ente(),
    colisao(false),
    colisaoCima(false),
    gravidade(true), 
    noChao(false), 
    //isMoving(false),
    speed(Vector2f(0.0f, 0.0f))
{
    //Posicao padrao de todas as entidades
    corpo.setPosition(Vector2f(200.f, 500.f));
    ID = 0;
}


Entidade::~Entidade(){}

void Entidade::setVelocidade(Vector2f velocidade)
{
    speed = velocidade;
}

Vector2f* Entidade::getVelocidade()
{
    return &speed;
}

RectangleShape Entidade::getCorpo(){ return corpo; }

void Entidade::setColor(sf::Color cor)
{
    corpo.setFillColor(cor);
}

const int Entidade::getId()
{
    return ID;
}

void Entidade::setColisao(bool a)
{
    colisao = a;
}

void Entidade::setDirecaoColisao(bool d)
{
    colisaoCima = d;
}

const bool Entidade::getDirecaoColisao()
{
    return colisaoCima;
}

void Entidade::movGravidade()
{
    if (colisao == false)
        gravidade = true;

    if (gravidade) {

        //Equação horária da posição
        //speed.y = (speed.y * GerenciadorGrafico::dt) + ((GRAVIDADE * GerenciadorGrafico::dt)/2);
        
        //Manipulação da integração de Euler = (Velocidade + posicao atual) + acelaracao
        //Velocidade + posicao atual = corpo.move -> ele soma a posicao atual mais o valor da velocidade

        //MAIS REALISTA

        
        //tempo ao quadrado (Gravidade = 998.0)
        float acelaracao = GRAVIDADE * GerenciadorGrafico::dt;
        speed.y += acelaracao * GerenciadorGrafico::dt;
        
        /*
        //tempo eleavdo a 1 (Gravidade = 9.98)
        double acelaracao = GRAVIDADE * GerenciadorGrafico::dt;
        speed.y += acelaracao;
        */

        corpo.move(Vector2f(0.0f, speed.y));

    }
}


void Entidade::corrigeColisoes(Entidade* a, Vector2f inter)
{
    // Codigo baseado na video aula do monitor Matheus Burda:
    // https://www.youtube.com/watch?v=mxZMK7ZqFtE&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=9
    
    Vector2f aPos = a->getCorpo().getPosition();
    
    //So vai ser true se a natureza da colisao for de cima para baixo 
    a->setDirecaoColisao(false);

    //Colisao em x
    if (inter.x > inter.y) {
        if (corpo.getPosition().x < aPos.x)
        {
            corpo.move(Vector2f(inter.x, 0.0f));
        }

        else
        {
            corpo.move(Vector2f(-inter.x, 0.0f));
        }

        speed.x = 0.0f;

    }

    //Colisao em y
    else 
    {
        if (corpo.getPosition().y < aPos.y) {

            corpo.move(Vector2f(0.f, inter.y));

            //Se a entidade colidida nao for uma plataforma, quer dizer que o objeto que chamou essa funcao esta em cima
            if (a->getId() != 3) {
                a->setDirecaoColisao(true);
            }
        }

        else {
            corpo.move(Vector2f(0.f, -inter.y));
        }
        speed.y = 0.0f;
    }


}

void Entidade::verificaColisaoPlataforma(Entidade* e)
{
    //Plataforma
    if (e->getId() == 3)
    {
        gravidade = false;
        noChao = true;

        //Zera a velocidade
        speed.y = 0.0f;
    }
}

void Entidade::setPosEntidade(Vector2f pos)
{
    corpo.setPosition(pos);
}

void Entidade::movimentaEntidade(Vector2f mov)
{
    corpo.move(mov);
}


