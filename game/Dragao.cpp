#include "Dragao.h"

Dragao::Dragao(): Inimigo(), tempo_de_ataque(1.0)
{
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

}

void Dragao::Executar()
{
    verificaVida();
    Mover();
}

void Dragao::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    ID id_entidade = entidade->getId();
    Personagens* jogador = static_cast<Personagens*>(entidade);

    //Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
    if (id_entidade == ID::jogador){
        
        if (olhandoDireita) {
            repulsao.x = -60.0;
            verificaPodeAndar(repulsao);
            if(podeAndarEsquerda)
                movimentaEntidade(Vector2f(repulsao.x, repulsao.y));
        }
        else if (olhandoEsquerda) {
            repulsao.x = 60.0;
            verificaPodeAndar(repulsao);
            if(podeAndarDireita)
                movimentaEntidade(repulsao);
        }

        //Ataque
        atacar(jogador, dano);
    }
       
    else
    {
        corrigeColisoes(entidade, inter_colisao);
    }

}
