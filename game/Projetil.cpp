#include "Projetil.h"

Projetil::Projetil():portador(nullptr), repouso(true), t()
{
	//Forma Projetil
	corpo.setSize(Vector2f(10.f, 5.f));
	corpo.setFillColor(Color::Magenta);

	//Atributos Projetil
	setVelocidade(Vector2f(5.0f, 0.f));
	dano = 3.5f;

	id = ID::projetil;

	estadoInicial();

}


Projetil::~Projetil()
{
	
	if (portador)
		portador = nullptr;

}


//ESTADO INICIAL

void Projetil::verificarBordas()
{

	if (verificarPosInvalida())
	{
		estadoInicial();
	}
}

void Projetil::estadoInicial()
{
	if (portador) {
		atualizaPosicaoInicial();
		visivel = false;
		repouso = true;
	}
}

void Projetil::atualizaPosicaoInicial()
{
	Vector2f posPortador = portador->getCorpo().getPosition();
	setPosEntidade(Vector2f(posPortador.x, posPortador.y + 5.f));
}

const bool Projetil::getRepouso()
{
	return repouso;
}

//PORTADOR

void Projetil::setPortador(Personagens* portador)
{
	this->portador = portador;
	estadoInicial();
}

const Personagens* Projetil::getPortador() const
{
	return portador;
}



// ATAQUE

void Projetil::atacar(Entidade* adversario, float dano)
{

	//Quando colidir eu chamo essa funcao que ataca o adversario
	if (adversario->getId() == ID::jogador) {

		Personagens* adv = static_cast<Personagens*>(adversario);
		adv->perdeVida(dano);
	}

}

void Projetil::atirar(string direcao, float tempo)
{

	tempo_ataque = t.getElapsedTime().asSeconds();

	if (repouso && tempo_ataque >= tempo) {

		t.restart();
		atualizaPosicaoInicial();

		visivel = true;
		repouso = false;
		speed.y = -1.f;

		//Aqui dentro para ele nao mudar a direcao no meio da trajetoria
		if (direcao == "direita")
			speed.x = 5.0f;

		else if (direcao == "esquerda")
			speed.x = -5.0f;

		corpo.move(speed);
	}

	else if (!repouso) {
		//Mantem a trajetoria do projetil
		corpo.move(Vector2f(speed.x, 0.f));
	}
}

void Projetil::Executar()
{
	//Se o projetil colide com as bordas ele volta ao seu estado inicial
	verificarBordas();

	//Sempre atualiza a posicao do projetil
	if (repouso)
		estadoInicial();
	else
		movGravidade();
}

void Projetil::Colisao(Entidade* entidade, Vector2f inter_colisao)
{

	corrigeColisoes(entidade, inter_colisao);

	if (entidade->getId() == ID::jogador) {
		//Quando colide eu chamo o atacar (que causa dano no adversario)
		atacar(entidade, dano);
	}

	//Volto para a estado inicial
	estadoInicial();
}
