#include "Jogador.h"



Jogador::Jogador():Personagens(), tempo()
{
    setVelocidade(Vector2f(10.f, 0.f));
    ID = 1;
    std::cout << vivo << endl;
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

    int id_entidade = entidade->getId();
    Vector2i olhar_entidade;


    float t = tempo.getElapsedTime().asSeconds();

    corrigeColisoes(entidade, inter_colisao);
    

    //TEM Q SER UMA COLISAO NA DIREÇÃO DE Y

    //Plataforma
    verificaColisaoPlataforma(entidade);
    
    //Dragao -> joga pta cima e pro lado a cada 1.5 segundos
    if (id_entidade == 10)
    {
        Dragao* dragao = static_cast<Dragao*>(entidade);
        olhar_entidade = dragao->getOlhar();


        if (t >= 1.0) {
           
            if (olhandoDireita)
            {
                corpo.move(Vector2f(-50.f, 0.0f));
            }
            else
            {
                corpo.move(Vector2f(120.f, -0.0f));
            }
            //pular(0.08);
            perdeVida();
            tempo.restart();
        }

        cout << dragao->getQuantidadeVida() << endl;

        dragao->perdeVida();    

    }

    
    //Hydra
    else if (id_entidade == 15)
    {
        Vector2f repulsao(15.0, 0.0);

        Personagens* hydra = static_cast<Personagens*>(entidade);
        olhar_entidade = hydra->getOlhar();

        // Começa a perseguir o jogador
        hydra->setAtacou(true);

        //Se o jogador ta em cima dela, ela perde vida
        if (hydra->getDirecaoColisao())
        {
            noChao = true;
            //hydra->perdeVida();
        }
        else
        {
            if (olhandoDireita || olhar_entidade.y == 1)
            {
                repulsao.x = -15.0;
                verificaPodeAndar(repulsao);
                
                if (podeAndarEsquerda)
                    corpo.move(repulsao);
                else
                    hydra->setAtacou(false); // para parar a hydra
            }
            else if (olhandoEsquerda || olhar_entidade.x == 1) {
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


