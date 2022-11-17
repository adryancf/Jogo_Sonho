#include "Jogador.h"



Jogador::Jogador():Personagens(), tempo()
{
    setVelocidade(Vector2f(10.f, 0.f));
    id = ID::jogador;
}

void Jogador::iniciar()
{

}
Jogador::~Jogador(){}

void Jogador::Mover()
{
    
    //Representar quando ele ta parado
    olhandoDireita = false;
    olhandoEsquerda = false;

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

    float t = tempo.getElapsedTime().asSeconds();

    Vector2<bool> olhar_entidade;

    corrigeColisoes(entidade, inter_colisao);
    
    if (entidade->getId() == ID::dragao)
    {
        Vector2f repulsao(0.0, 0.0);
        Dragao* dragao = static_cast<Dragao*>(entidade);
        olhar_entidade = dragao->getOlhar();

        //ESSE OLHAR DA ENTIDADE Q TA MEIO BUGADO (PENSAR COM MAIS CALMA)
        
        if (!emCima) 
        {
            if (olhandoDireita || olhar_entidade.y)
            {
                repulsao.x = -60.0;

                verificaPodeAndar(repulsao);
                dragao->verificaPodeAndar(repulsao);

                if (podeAndarEsquerda == true)
                {
                    corpo.move(repulsao);
                    //dragao->movimentaEntidade(Vector2f(40.0, 0.0f));
                }
            }

            else if (olhandoEsquerda || olhar_entidade.x)
            {
                repulsao.x = 60.0;

                verificaPodeAndar(repulsao);
                dragao->verificaPodeAndar(repulsao);

                if (podeAndarDireita == true)
                {
                    corpo.move(repulsao);
                    //dragao->movimentaEntidade(Vector2f(-40.0, repulsao.y));

                }
            }
          
            else
                cout << "NAO DA PRA SE MOVER" << endl;


            //Nao esta funcionando (nao to entendendo)
            //pular(0.05);

            //perdeVida();

            dragao->perdeVida();
            tempo.restart();
        }
       

     
    }

    //Hydra
    else if (entidade->getId() == ID::hydra)
    {
        Vector2f repulsao(15.0, 0.0);

        Personagens* hydra = static_cast<Personagens*>(entidade);
        olhar_entidade = hydra->getOlhar();

        // Começa a perseguir o jogador
        hydra->setAtacou(true);

        //Se o jogador ta em cima dela, ela perde vida
        if (emCima)
        {
            hydra->perdeVida();
        }
        else
        {
            if (olhandoDireita || olhar_entidade.y)
            {
                repulsao.x = -15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarEsquerda)
                    corpo.move(repulsao);
                else
                    hydra->setAtacou(false);
            }


            else if (olhandoEsquerda || olhar_entidade.x)  {
                repulsao.x = 15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarDireita)
                    corpo.move(repulsao);
                else
                    hydra->setAtacou(false);
            }
        }
    }
}


