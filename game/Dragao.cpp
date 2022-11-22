#include "Dragao.h"

Dragao::Dragao(): Inimigo(), tempo_de_ataque(1.0)
{
    id = ID::dragao;
    inicializa();
    texture.loadFromFile("assets/NinjaFrog.png");
    corpo.setTexture(&texture);
    corpo.setSize(sf::Vector2f(80.0f, 80.0f));
}

Dragao::~Dragao()
{
}

void Dragao::inicializa()
{
    //Forma Dragao
    corpo.setSize(Vector2f(DRAGAO_X, DRAGAO_Y));
    //setColor(Color::Red);

    //Atributos Dragao
    setVelocidade(Vector2f(0.6f, 0.f));
    setQuantidadeVida(3.0);
    setDano(0.5);

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

    corrigeColisoes(entidade, inter_colisao);

    //Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
    if (id_entidade == ID::jogador) {

        if (direcaoMovimento != "nulo") {
            if (direcaoMovimento == "esquerda")
            {
                repulsao.x = -30.0;
                movimentaEntidade((repulsao), false);

            }
            else if (direcaoMovimento == "direita")
            {
                repulsao.x = 30.0;
                movimentaEntidade(repulsao, true);


            }
        }

        else
        {
            if (olhandoDireita) {
                repulsao.x = -60.0;
                movimentaEntidade(repulsao, false);
            }
            else if (olhandoEsquerda) {
                repulsao.x = 60.0;
                movimentaEntidade(repulsao, true);
            }

            
        }

        //Ataque
        Personagens* jogador = static_cast<Personagens*>(entidade);

        if(jogador->getEmCima() == false)
            atacar(jogador, dano);
    }
  

}
