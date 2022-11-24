#include "Fantasma.h"

Fantasma::Fantasma(): Inimigo(), tempo_de_ataque(1.0)
{
    id = ID::fantasma;
    inicializa();

    sf::IntRect rect(1, 4, 30, 27);
    texture.loadFromFile("assets/ghost-Sheet.png", rect);
    corpo.setTexture(&texture);
    corpo.setSize(sf::Vector2f(60.0f, 60.0f));
}

Fantasma::~Fantasma()
{
}

void Fantasma::inicializa()
{
    //Forma Fantasma
    corpo.setSize(Vector2f(DRAGAO_X, DRAGAO_Y));
    //setColor(Color::Red);

    //Atributos Fantasma
    setVelocidade(Vector2f(0.6f, 0.f));
    setQuantidadeVida(3.0);
    setDano(0.5);

}

const float Fantasma::getTempoAtaque() const
{
    return tempo_de_ataque;
}


void Fantasma::Mover()
{
    //Aplica a gravidade
    movGravidade();
    movAleatorio();

    direcaoMovimento = string("nulo");

}

void Fantasma::Executar()
{
    verificaVida();
    //cout << " Vida Dragao: " << q_vida << endl;

    Mover();
}

void Fantasma::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    ID id_entidade = entidade->getId();

    //Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
    if (id_entidade == ID::jogador) {

        Personagens* jogador = static_cast<Personagens*>(entidade);

        if (direcaoMovimento != "nulo") {
            cout << direcaoMovimento << endl;
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
                jogador->setDirecaoMovimento(string("direita"));

            }
            else if (olhandoEsquerda) {
                repulsao.x = 60.0;
                movimentaEntidade(repulsao, true);
                jogador->setDirecaoMovimento(string("esquerda"));

            }

            
        }
        

        //Ataque
        
        if(jogador->getEmCima() == false)
            atacar(jogador, dano);
          
    }
  
    else
        corrigeColisoes(entidade, inter_colisao);

}
