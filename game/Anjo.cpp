#include "Anjo.h"

Anjo::Anjo(Jogador* p): Inimigo(), projetil(nullptr)
{
    player = p;

    //Forma Anjo
    corpo.setSize(Vector2f(50.f, 150.f));
    corpo.setFillColor(Color::Cyan);

    //Atributos Anjo
    setVelocidade(Vector2f(0.3f, 0.f));
    setQuantidadeVida(15.0);

    raio_deteccao = Vector2f(2000.f, 2000.f);

    //Dano Fisico
    setDano(2.0);

    //Dano Projetil
    //projetil->setDano(5.0);

    id = ID::anjo;

}

Anjo::Anjo(Personagens* alvo)
{
	projetil->setAlvo(alvo);
}

Anjo::~Anjo()
{
	projetil = nullptr;
}

const Projetil* Anjo::getProjetil()
{
    return projetil;
}

void Anjo::Mover()
{
    movGravidade();

    //Perseguir o Jogador
    if (podeAndar)
    {
        Vector2f posJogador = player->getCorpo().getPosition();
        Vector2f posInimigo = corpo.getPosition();

        if ((fabs(posJogador.x - posInimigo.x) <= raio_deteccao.x)
            && (fabs(posJogador.y - posInimigo.y) <= raio_deteccao.y)) {

            PersegueJogador(posJogador, posInimigo);
        }
    }

}

void Anjo::Executar()
{
    verificaVida();
    Mover();
}

void Anjo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();

	//Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
	if (id_entidade == ID::jogador) {
        Personagens* jogador = static_cast<Personagens*>(entidade);
    
        //Verifica se pode Perseguir
        podePerseguir(jogador);

        
        atacar(jogador, dano);
		
	}

	else
	{
		corrigeColisoes(entidade, inter_colisao);
	}





}


