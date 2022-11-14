#include "Hydra.h"

Hydra::Hydra(Jogador* j): Inimigo(), atacou(false)
{
	jogador = j;

	//Forma Hydra
	corpo.setSize(Vector2f(100.f, 100.f));
	corpo.setFillColor(Color::Blue);
	corpo.setPosition(Vector2f(0.f, 0.f));

	//Atributos Hydra
	setVelocidade(Vector2f(5.0f, 0.f));
	setQuantidadeVida(4);

	raio_detecção.x = 50.f;
	raio_detecção.y = 50.f;

}

Hydra::~Hydra()
{
	jogador = nullptr;
}

void Hydra::Mover()
{
	if (atacou)
	{
		Vector2f posJogador = jogador->getCorpo().getPosition();
		Vector2f posInimigo = corpo.getPosition();

		if ((fabs(posJogador.x - posInimigo.x) <= raio_detecção.x) && (fabs(posJogador.y - posInimigo.y) <= raio_detecção.y)) {
			PersegueJogador(posJogador, posInimigo);
		}
	}

}

void Hydra::Executar()
{
	Mover();
}

void Hydra::setAtacou(bool ataque)
{
	atacou = ataque;
}

void Hydra::PersegueJogador(Vector2f posJogador, Vector2f posInimimgo)
{
	//funçao altera as flags 
	verificaPodeAndar();

	if ((posJogador.x - posInimimgo.x) > 0.0f && podeAndarDireita) { corpo.move(speed.x, 0.0f); }
	else if (podeAndarEsquerda) { corpo.move(-speed.x, 0.0f); }
}
