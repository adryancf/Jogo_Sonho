#include "Entidade.h"

/*
ID Entidade::getId() const
{
    return id;
}
*/
Entidade::Entidade(ID idd) : corpo(Vector2f(70.f, 70.f)),
    Ente(),
    colisaoPlataforma(false),
    gravidade(true), 
    noChao(false), 
    emCimaEntidade(false),
    speed(Vector2f(0.0f, 0.0f)),
    repulsao_direita(Vector2f(0.0f, 0.0f)),
    repulsao_esquerda(Vector2f(0.0f, 0.0f)),
    dano(0.0f)
{
   
}


Entidade::~Entidade(){}

void Entidade::render()
{
    pGrafico->desenhar(corpo);
}

//TRUE: ESTA FORA DO MAPA | FALSE: ESTA DENTRO DO MAPA
const bool Entidade::verificarPosInvalida()
{
    Vector2f pos_ent(getPosicao());

    if (pos_ent.x < 0.0f || pos_ent.x > RESOLUCAO_X - getSizeCorpo().x)
        return true;
    else if (pos_ent.y > RESOLUCAO_Y + getSizeCorpo().y)
        return true;
    else
        return false;

}

const bool Entidade::verificarPosInvalidaEmY()
{
    Vector2f pos_ent(getPosicao());

    if (pos_ent.y > RESOLUCAO_Y + getSizeCorpo().y)
        return true;
    else
        return false;
}

void Entidade::setVelocidade(Vector2f velocidade)
{
    speed = velocidade;
}

Vector2f Entidade::getVelocidade()
{
    return speed;
}


void Entidade::setDano(float dano)
{
    this->dano = dano;
}

const float Entidade::getDano() const
{
    return dano;
}

const RectangleShape Entidade::getCorpo() const
{ 
    return corpo; 
}

const Vector2f Entidade::getSizeCorpo() const
{
    return corpo.getSize();
}

void Entidade::setColor(sf::Color cor)
{
    corpo.setFillColor(cor);
}

const Vector2f Entidade::getPosicao() const
{
    return corpo.getPosition();
}


void Entidade::setColisaoPlataforma(bool estaNaPlataforma)
{
    colisaoPlataforma = estaNaPlataforma;
}

void Entidade::setChao(bool estaNoChao)
{
    noChao = estaNoChao;
}


const bool Entidade::getEmCima()
{
    return emCimaEntidade;
}

void Entidade::movGravidade()
{   
    if (colisaoPlataforma){ 
        noChao = true;
    }


    else{ noChao = false; }
        
    //Manipula��o da integra��o de Euler = (Velocidade + posicao atual) + acelaracao
    //(Velocidade + posicao atual) = corpo.move -> ele soma a posicao atual mais o valor da velocidade
    
    if (gravidade) {
     
        //tempo ao quadrado (Gravidade = 998.0) | MAIS REALISTA
        float acelaracao = GRAVIDADE * GerenciadorGrafico::dt;
        speed.y += acelaracao * GerenciadorGrafico::dt;

        corpo.move(Vector2f(0.0f, speed.y));

        /*
        //tempo eleavdo a 1 (Gravidade = 9.98)
        double acelaracao = GRAVIDADE * GerenciadorGrafico::dt;
        speed.y += acelaracao;
        */

    }

}


//CADA ENTIDADE CORRIGE SUA COLISAO (ELE SE MOVE PARA TRAS)
void Entidade::corrigeColisoes(Entidade* a, Vector2f inter)
{
    // Codigo baseado na video aula do monitor Matheus Burda:
    // https://www.youtube.com/watch?v=mxZMK7ZqFtE&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=9
    
    Vector2f entidadeEmColisao = a->getPosicao();
    
    //So vai ser true se a natureza da colisao for de cima para baixo 
    emCimaEntidade = false;

    //Colisao em x
    if (inter.x >= inter.y) {
        if (getPosicao().x < entidadeEmColisao.x)
        {
            corpo.move(Vector2f(inter.x, 0.0f));
        }

        else
        {
            corpo.move(Vector2f(-inter.x, 0.0f));
        }

        //speed.x = 0.0f;

    }

    //Colisao em y
    else 
    {
        if (getPosicao().y < entidadeEmColisao.y) {

            corpo.move(Vector2f(0.f, inter.y));

            //Só importa se estou em cima de alguma entidade
            if (a->getId() != ID::plataforma || a->getId() != ID::caixa || a->getId() != ID::espinho) {
                emCimaEntidade = true;
            }
        }

        else {
            corpo.move(Vector2f(0.f, -inter.y));
        }

        speed.y = 0.0f;
    }

}


void Entidade::setPosEntidade(Vector2f pos)
{
    corpo.setPosition(pos);
}



