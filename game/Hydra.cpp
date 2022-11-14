#include "Hydra.h"

Hydra::Hydra(Jogador* j): Inimigo(), atacou(false)
{
	jogador1 = j;

	cout << "CRIEI" << endl;

	//Forma Hydra
	corpo.setSize(Vector2f(100.f, 100.f));
	corpo.setFillColor(Color::Blue);
	corpo.setPosition(Vector2f(50.f, 50.f));

	//Atributos Hydra
	setVelocidade(Vector2f(5.0f, 0.f));
	setQuantidadeVida(4);

	raio_detec��o.x = 50.f;
	raio_detec��o.y = 50.f;

	cout << "Posi��o: " << corpo.getPosition().x << corpo.getPosition().y << endl;

}

Hydra::~Hydra()
{
	jogador1 = nullptr;
}

void Hydra::Mover()
{

	movGravidade();

	if (atacou)
	{
		Vector2f posJogador = jogador1->getCorpo().getPosition();
		Vector2f posInimigo = corpo.getPosition();

		if ((fabs(posJogador.x - posInimigo.x) <= raio_detec��o.x) && (fabs(posJogador.y - posInimigo.y) <= raio_detec��o.y)) {
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
	//fun�ao altera as flags 
	verificaPodeAndar();

	if ((posJogador.x - posInimimgo.x) > 0.0f && podeAndarDireita) { corpo.move(speed.x, 0.0f); }
	else if (podeAndarEsquerda) { corpo.move(-speed.x, 0.0f); }
}
