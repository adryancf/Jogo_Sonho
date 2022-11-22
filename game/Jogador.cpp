#include "Jogador.h"

Jogador::Jogador():Personagens(), tempo(), pontuacao(0)
{
    id = ID::jogador;
    texture.loadFromFile("assets/PinkMan.png");
    corpo.setTexture(&texture);
    iniciar();
    corpo.setSize(sf::Vector2f(70.0f, 70.0f));
}

void Jogador::iniciar()
{
    //Atributos Jogador
    corpo.setSize(Vector2f(JOGADOR_X, JOGADOR_Y));
    //this->setTextura();

    setVelocidade(Vector2f(10.f, 0.f));
    setQuantidadeVida(10.0);
    setDano(3.0);
}
Jogador::~Jogador(){
    pontuacao = 0;
}


void Jogador::Mover()
{
    movGravidade();
}

void Jogador::Executar()
{
    verificaVida();
    cout << " Vida Jogador: " << q_vida << endl;
    Mover();
}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUNÇÕES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    speed.x = 10.f;

    if (i == 2)
    {
        movimentaEntidade(Vector2f(-speed.x, 0), false);
    }
    else if (i == 4)
    {
        movimentaEntidade(Vector2f(speed.x, 0), true);
    }
}

void Jogador::ganhaPontos(int pontos)
{
    pontuacao += pontos;
}

void Jogador::ganhaPontos()
{
    pontuacao++;
}

void Jogador::perdePontos(int pontos)
{
    pontuacao -= pontos;
}

void Jogador::perdePontos()
{
    pontuacao--;
}

const int Jogador::getPontos()
{
    return pontuacao;
}

//GERENCIADOR DE COLISÕES
void Jogador::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    corrigeColisoes(entidade, inter_colisao);
    
    //Dragao
    if (entidade->getId() == ID::dragao)
    {
        Personagens* dragao = static_cast<Personagens*>(entidade);
        float t = tempo.getElapsedTime().asSeconds();

        //So tem repulsao quando nao esta em cima
        if (!emCima) 
        {
            if (olhandoDireita) {
                repulsao.x = -30.0;
                verificaPodeAndar(repulsao);
                if (podeAndarEsquerda) {
                    movimentaEntidade(repulsao, false);

                    //Manda o dragao para direita
                    dragao->setDirecaoMovimento(string("direita"));
                }
            }
            else if (olhandoEsquerda) {
                repulsao.x = 30.0;
                verificaPodeAndar(repulsao);
                if (podeAndarDireita) {
                    movimentaEntidade(repulsao, true);

                    //Manda o dragao para esquerda
                    dragao->setDirecaoMovimento(string("esquerda"));
                }
            }

            atacar(entidade, dano);

        }
        
        tempo.restart();

    }
            
    //Hydra
    else if (entidade->getId() == ID::hydra)
    {
        //Se o jogador ta em cima dela, ela perde vida
        if (emCima) {
            atacar(entidade, dano);
            
        }

        else
        {
            if (olhandoDireita)
            {
                repulsao.x = -15.0;
                movimentaEntidade(repulsao, false);
            }

            else if (olhandoEsquerda)  {
                repulsao.x = 15.0;
                movimentaEntidade(repulsao, true);
            }
        }
    }
}

/*
void Jogador::setTextura()
{
    textura->loadFromFile("assets/mushroom.PNG");
}
*/


