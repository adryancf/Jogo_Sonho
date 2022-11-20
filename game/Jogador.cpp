#include "Jogador.h"

Jogador::Jogador():Personagens(), tempo()
{
    
    id = ID::jogador;  

    //Atributos Jogador
    setVelocidade(Vector2f(10.f, 0.f));
    setQuantidadeVida(10.0);
    setDano(1.0);
}

void Jogador::iniciar()
{

}
Jogador::~Jogador(){}

void Jogador::Mover()
{
    
    //Representar quando ele ta parado
    //olhandoDireita = false;
    //olhandoEsquerda = false;

    movGravidade();
}

void Jogador::Executar()
{
    verificaVida();
    Mover();
}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUNÇÕES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    speed.x = 10.f;

    verificaPodeAndar(speed);

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
    
    if (entidade->getId() == ID::dragao)
    {
        float t = tempo.getElapsedTime().asSeconds();

        if (!emCima) 
        {
            if (olhandoDireita) {
                repulsao.x = -60.0;
                verificaPodeAndar(repulsao);
                if (podeAndarEsquerda)
                    movimentaEntidade(repulsao);
            }
            else if (olhandoEsquerda) {
                repulsao.x = 60.0;
                verificaPodeAndar(repulsao);
                if (podeAndarDireita)
                    movimentaEntidade(repulsao);
            }
        }

        Personagens* dragao = static_cast<Personagens*>(entidade);
        
        if(t<=0.5)
            atacar(dragao, dano);


        tempo.restart();

    }
            
    //Hydra
    else if (entidade->getId() == ID::hydra)
    {

        Personagens* hydra = static_cast<Personagens*>(entidade);

        //Se o jogador ta em cima dela, ela perde vida
        if (emCima)
        {
            atacar(hydra, dano);
;       }

        else
        {
            if (olhandoDireita)
            {
                repulsao.x = -15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarEsquerda)
                    corpo.move(repulsao);
            }


            else if (olhandoEsquerda)  {
                repulsao.x = 15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarDireita)
                    corpo.move(repulsao);
            }
        }
    }
}


