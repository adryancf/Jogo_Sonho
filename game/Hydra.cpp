#include "Hydra.h"

Hydra::Hydra(Jogador* p): Inimigo()
{
	cout << "CRIEI" << endl;
	player = nullptr;
	player = p;

	//Forma Hydra
	corpo.setSize(Vector2f(100.f, 100.f));
	corpo.setFillColor(Color::Blue);
	corpo.setPosition(Vector2f(50.f, 50.f));

	//Atributos Hydra
	setVelocidade(Vector2f(0.5f, 0.f));
	setQuantidadeVida(4);

	raio_detec��o.x = 2000.f;
	raio_detec��o.y = 2000.f;

	//Enquanto nao tem o enum dos ids
	ID = 15;
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

		if ((fabs(posJogador.x - posInimigo.x) <= raio_detec��o.x) && (fabs(posJogador.y - posInimigo.y) <= raio_detec��o.y)) {
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
	//fun�ao altera as flags 
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
