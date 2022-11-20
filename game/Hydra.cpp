#include "Hydra.h"

Hydra::Hydra(Jogador* p): Inimigo()
{
	player = nullptr;
	player = p;

	//Forma Hydra
	corpo.setSize(Vector2f(55.f, 55.f));
	corpo.setFillColor(Color::Blue);

	//Atributos Hydra
	setVelocidade(Vector2f(0.3f, 0.f));
	setQuantidadeVida(4.0);
	setDano(1.0);

	raio_deteccao.x = 5000.f;
	raio_deteccao.y = 5000.f;

	//Enquanto nao tem o enum dos ids
	id = ID::hydra;
}

Hydra::~Hydra()
{
	player = nullptr;
}

void Hydra::Mover()
{
	movGravidade();
	//podeAndar = true;

	//cout << "Atacou: " << atacou << "Pode Andar: " << podeAndar << endl;

	if (atacou == true && podeAndar == true)
	{
		Vector2f posJogador = player->getCorpo().getPosition();
		Vector2f posInimigo = corpo.getPosition();

		if ((fabs(posJogador.x - posInimigo.x) <= raio_deteccao.x) 
			&& (fabs(posJogador.y - posInimigo.y) <= raio_deteccao.y)) {

			PersegueJogador(posJogador, posInimigo);
		}
	}

}

void Hydra::PersegueJogador(Vector2f posJogador, Vector2f posInimimgo)
{
	//funçao altera as flags 
	verificaPodeAndar(speed);
	Vector2f diferenca = posJogador - posInimimgo;

	if ((diferenca.x > 0) && podeAndarDireita) {

		cout << "DIREITA" << endl;
		movimentaEntidade(Vector2f(speed.x, 0.0), true);
	}

	else if((diferenca.x < 0) && podeAndarEsquerda)
	{
		
		cout << "ESQUERDA" << endl;
		movimentaEntidade(Vector2f(-speed.x, 0.0), false);
		
	}

	//PENSAR EM UMA FORMA PARA PERSEGUIR EM Y

	/*
	else if (diferenca.y > 0.0 || diferenca.y < 0.0)
	{
		cout << "ENTREI " << endl;
		if (podeAndarDireita == true) {
			movimentaEntidade(Vector2f(speed.x, 0.0), true);
		}
		else if (podeAndarEsquerda == true) {
			movimentaEntidade(Vector2f(-speed.x, 0.0), false);
			
		}	 
	}
	*/

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

		Vector2<bool> podeAndarJogador;
		Personagens* jogador = static_cast<Personagens*>(entidade);

		if (olhandoDireita) {
			
			repulsao.x = 15.0;
			jogador->verificaPodeAndar(repulsao);
			podeAndarJogador = jogador->getPodeAndar();

			if (podeAndarJogador.x)
				podeAndar = true;
			else if(!podeAndarJogador.x)
				podeAndar = false;
		}
		else if (olhandoEsquerda) {
			repulsao.x = -15.0;
			jogador->verificaPodeAndar(repulsao);
			podeAndarJogador = jogador->getPodeAndar();

			if (podeAndarJogador.y)
				podeAndar = true;
			else if(!podeAndarJogador.y)
				podeAndar = false;
		}

		//Ataque
		if(jogador->getEmCima() == false)
			atacar(jogador, dano);
	}

	else
	{
		corrigeColisoes(entidade, inter_colisao);
	}
}


