#include "Hydra.h"

Hydra::Hydra(Jogador* p1, Jogador* p2): Inimigo(), posHydra(Vector2f(0.0f, 0.0f))
{
	player1 = p1;
	player2 = p2;
	id = ID::hydra;

	inicializa();
	texture.loadFromFile("assets/MaskDude.png");
	corpo.setTexture(&texture);
	//corpo.setSize(sf::Vector2f(70.0f, 70.0f));
}

Hydra::~Hydra()
{
	player1 = nullptr;
	player2 = nullptr;
}

void Hydra::inicializa()
{
	//Forma Hydra
	corpo.setSize(Vector2f(HYDRA_X, HYDRA_Y));
	//corpo.setFillColor(Color::Blue);

	//Atributos Hydra
	setVelocidade(Vector2f(0.3f, 0.f));
	setQuantidadeVida(4.0);
	setDano(1.0);

	repulsao_direita = Vector2f(40.f, 0.f);
	repulsao_esquerda = Vector2f(-40.f, 0.f);

	raio_deteccao.x = 300.f;
	raio_deteccao.y = 300.f;
}

void Hydra::Mover()
{
	movGravidade();

	if (atacou == true && podeAndar == true)
	{
		Vector2f posJogador1 = player1->getPosicao();
		Vector2f posJogador2 = player2->getPosicao();

		posHydra = corpo.getPosition();

		//Verifica o jogador mais proximo e ja persegue
		qualPerseguir(posJogador1, posJogador2, posHydra);
		
		
	}

}


void Hydra::Executar()
{
	verificaVida();
	Mover();
}

void Hydra::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();

	//Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
	if (id_entidade == ID::jogador) {
		atacou = true;

		//Ataque (S� ataca quando o jogador nao tiver em cima)
		Jogador* jogador = static_cast<Jogador*>(entidade);

		jogadorEmCima = jogador->getEmCima();

		if (!jogadorEmCima) {
			//Se o jogador estiver em movimento
			

			if (jogador->getOlhar()) {
				jogador->movimentaEntidade(repulsao_esquerda, false);
			}
			else if (!jogador->getOlhar()) {
				jogador->movimentaEntidade(repulsao_direita, true);
			}
			
			atacar(jogador, dano);
		}

		else if (jogadorEmCima) {
			//JOGADOR ATACA A ENTIDADE
			jogador->atacar(this, jogador->getDano());
		}
			


	}

	else
		corrigeColisoes(entidade, inter_colisao);



}


