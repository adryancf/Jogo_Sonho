#include "Anjo.h"

Anjo::Anjo(Jogador* p, Projetil* b): 
    Inimigo(), 
    projetil(b),
    tempo_atk(1.0f),
    estaNoRaio(false),
    posAlvo(Vector2f(0.f, 0.f))
{
    player = p;
    id = ID::anjo;

    inicializa();

}

Anjo::~Anjo()
{
    if (alvo)
        alvo = nullptr;

    if(projetil)
        projetil = nullptr;
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

void Anjo::inicializa()
{
    //Forma Anjo
    corpo.setSize(Vector2f(ANJO_X, ANJO_Y));
    setColor(Color::Cyan);

    //Atributos Anjo
    setVelocidade(Vector2f(0.5f, 0.f));
    setQuantidadeVida(15.0);

    raio_deteccao = Vector2f(500.f, 100.f);

    //Dano Fisico
    setDano(2.5);
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


void Anjo::atacar()
{
    
    //O ataque do anjo é lançar o projetil
    
    //Lança de 1 em 1s
    if (estaNoRaio)
    {
        //Liberar projetil
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
    atacar();
}

void Anjo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();
    corrigeColisoes(entidade, inter_colisao);


	//Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
	if (id_entidade == ID::jogador) {
        Personagens* jogador = static_cast<Personagens*>(entidade);
    
        //atacar(jogador, dano);
	}

}


