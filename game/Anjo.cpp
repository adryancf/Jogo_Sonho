#include "Anjo.h"

Anjo::Anjo(Jogador* p, Projetil* b): 
    Inimigo(), 
    projetil(b),
    tempo_atk(1.0f),
    posAlvo(Vector2f(0.f, 0.f))
{
    player = p;
    id = ID::anjo;

    inicializa();
    //texture.loadFromFile("assets/VirtualGuy.png");
    //corpo.setTexture(&texture);
    //corpo.setSize(sf::Vector2f(70.0f, 70.0f));

}

Anjo::~Anjo()
{
    if (alvo)
        alvo = nullptr;

    if(projetil)
        projetil = nullptr;
}

void Anjo::inicializa()
{
    //Forma Anjo
    corpo.setSize(Vector2f(ANJO_X, ANJO_Y));
    setColor(Color::Cyan);

    //Atributos Anjo
    setVelocidade(Vector2f(0.5f, 0.f));
    setQuantidadeVida(15.0);

    raio_deteccao = Vector2f(500.f, JOGADOR_Y);

    repulsao_direita = Vector2f(50.f, 0.f);
    repulsao_esquerda = Vector2f(-50.f, 0.f);

    //Dano Fisico
    //setDano(1.5f);
    if (projetil)
        projetil->setDano(0.0f);
}

void Anjo::setAlvo(Personagens* alvo)
{
    this->alvo = alvo;
}

const Personagens* Anjo::getAlvo() const
{
    return alvo;
}

const Projetil* Anjo::getProjetil()
{
    return projetil;
}



void Anjo::EncontraPosAlvo()
{
    //Encontra a posicao do alvo e pra que lado ele esta
    posAlvo = alvo->getPosicao();

    Vector2f diferenca = (getPosicao() - posAlvo);

    if (diferenca.x < 0.00f)
        direcao_alvo = "direita";
    else
        direcao_alvo = "esquerda";
    
}


void Anjo::atirar_projetil()
{
      
    //Lança de 1 em 1s
    
    //Liberar projetil
    if (estaNoRaio || projetil->getRepouso() == false) {
        EncontraPosAlvo();

        if (projetil)
            projetil->atirar(direcao_alvo, tempo_atk);

    }
    
}

void Anjo::Mover()
{
    movGravidade();

    //Perseguir o Jogador
    podePerseguir(player);

    if (podeAndar)
    {
        Vector2f posJogador = player->getCorpo().getPosition();
        Vector2f posInimigo = corpo.getPosition();

        if ((fabs(posJogador.x - posInimigo.x) <= raio_deteccao.x)
            && (fabs(posJogador.y - posInimigo.y) <= raio_deteccao.y)) {
            PersegueJogador(posJogador, posInimigo);
            estaNoRaio = true;
        }
        else
            estaNoRaio = false;
    }

}

void Anjo::Executar()
{
    verificaVida();
    Mover();
    atirar_projetil();

}

void Anjo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();

    if (id_entidade == jogador) {

        //Ataque (Só ataca quando o jogador nao tiver em cima)
        Personagens* jogador = static_cast<Personagens*>(entidade);

        jogadorEmCima = jogador->getEmCima();

        if (!jogadorEmCima) {

            if (jogador->getEstadoMovimentoJogador() == true) {

                if (jogador->getOlhar()) {
                    jogador->movimentaEntidade(repulsao_esquerda, false);
                }
                else if (!jogador->getOlhar()) {
                    jogador->movimentaEntidade(repulsao_direita, true);
                }
            }
            else
            {
                cout << "ENTREI" << endl;
                cout << "Diretia:" << olhandoDireita << endl;
                cout << "Esquerda:" << olhandoEsquerda << endl;
                if (olhandoDireita) {
                    jogador->movimentaEntidade(repulsao_direita, true);

                }
                else if (olhandoEsquerda) {
                    jogador->movimentaEntidade(repulsao_esquerda, false);

                }


            }
            atacar(jogador, dano);
            jogador->atacar(this, jogador->getDano());
        }
    }
    else
        corrigeColisoes(entidade, inter_colisao);

}


