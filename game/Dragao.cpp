#include "Dragao.h"

Dragao::Dragao(): Inimigo(), tempo_de_ataque(1.0)
{
    player = nullptr;

    //Forma Dragao
    corpo.setSize(Vector2f(25.f, 70.f));
    corpo.setFillColor(Color::Red);
    
    //Atributos Dragao
    setVelocidade(Vector2f(0.6f, 0.f));
    setQuantidadeVida(3.0);
    setDano(0.5);

    id = ID::dragao;

}

Dragao::~Dragao()
{
}

const float Dragao::getTempoAtaque() const
{
    return tempo_de_ataque;
}

void Dragao::Mover()
{
    //Aplica a gravidade
    movGravidade();
    movAleatorio();

    direcaoMovimento = string("nulo");

}

void Dragao::Executar()
{
    verificaVida();
    cout << " Vida Dragao: " << q_vida << endl;

    Mover();
}

void Dragao::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    ID id_entidade = entidade->getId();
   
    //Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
    if (id_entidade == ID::jogador) {

        if (direcaoMovimento != "nulo") {
            if (direcaoMovimento == "esquerda")
            {
                repulsao.x = -30.0;
                verificaPodeAndar(repulsao);
                if (podeAndarEsquerda)
                    movimentaEntidade((repulsao), false);

            }
            else if (direcaoMovimento == "direita")
            {
                repulsao.x = 30.0;
                verificaPodeAndar(repulsao);
                if (podeAndarDireita)
                    movimentaEntidade(repulsao, true);


            }
        }

        else
        {
            if (olhandoDireita) {
                repulsao.x = -60.0;
                verificaPodeAndar(repulsao);
                if (podeAndarEsquerda)
                    movimentaEntidade(Vector2f(repulsao.x, repulsao.y), false);
            }
            else if (olhandoEsquerda) {
                repulsao.x = 60.0;
                verificaPodeAndar(repulsao);
                if (podeAndarDireita)
                    movimentaEntidade(repulsao, true);
            }

            
        }

        //Ataque

        Personagens* jogador = static_cast<Personagens*>(entidade);

        if(jogador->getEmCima() == false)
            atacar(jogador, dano);
    }
       
    else
    {
        corrigeColisoes(entidade, inter_colisao);
    }

}
