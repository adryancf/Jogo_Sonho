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
	setQuantidadeVida(4);

	raio_deteccao.x = 2000.f;
	raio_deteccao.y = 2000.f;

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

	if (atacou)
	{
		Vector2f posJogador = player->getCorpo().getPosition();
		Vector2f posInimigo = corpo.getPosition();

		if ((fabs(posJogador.x - posInimigo.x) <= raio_deteccao.x) && (fabs(posJogador.y - posInimigo.y) <= raio_deteccao.y)) {
			PersegueJogador(posJogador, posInimigo);
		}
	}

}

void Hydra::Executar()
{
	verificaVida();
	Mover();
}

void Hydra::PersegueJogador(Vector2f posJogador, Vector2f posInimimgo)
{
	//funçao altera as flags 
	verificaPodeAndar(speed);

	if ((posJogador.x - posInimimgo.x) > 0.0f && podeAndarDireita) { 
		corpo.move(speed.x, 0.0f);
		olhandoDireita = true;
		olhandoEsquerda = false;
	}
	else if (podeAndarEsquerda) { 
		corpo.move(-speed.x, 0.0f);
		olhandoDireita = false;
		olhandoEsquerda = true;
	}

	
}
