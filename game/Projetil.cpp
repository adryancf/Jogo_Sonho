#include "Projetil.h"

Projetil::Projetil(): alvo(nullptr), portador(nullptr)
{
	//Forma Projetil
	corpo.setSize(Vector2f(20.f, 5.f));
	corpo.setFillColor(Color::Red);

	//Atributos Projetil
	setVelocidade(Vector2f(1.0f, 0.f));

	id = ID::projetil;

}

Projetil::Projetil(Personagens* a): alvo(a), portador(nullptr)
{
}

Projetil::~Projetil()
{
	if(alvo)
		alvo = nullptr;

	if (portador)
		portador = nullptr;

}

void Projetil::setAlvo(Personagens* alvo)
{
	this->alvo = alvo;
}

const Personagens* Projetil::getAlvo() const
{
	return alvo;
}

void Projetil::EncontraPosAlvo()
{
	posicaoAlvo = alvo->getCorpo().getPosition();
}

void Projetil::estadoInicial()
{
	visivel = false;
	setPosEntidade(portador->getCorpo().getPosition());

}

void Projetil::setPortador(Personagens* portador)
{
	this->portador = portador;
	estadoInicial();
}

const Personagens* Projetil::getPortador() const
{
	return portador;
}

void Projetil::movimentoProjetil()
{
	visivel = true;
	//Trajetoria ate o alvo
	EncontraPosAlvo();

	speed.y = -sqrt(2.0 * GRAVIDADE * 0.05);

	if (corpo.getPosition().x != posicaoAlvo.x)
		speed.x *= GerenciadorGrafico::dt;

	corpo.move(speed);

}

void Projetil::atacar(Entidade* adversario, float dano)
{
	Personagens* adv = nullptr;

	//Quando colidir eu chamo essa funcao que ataca o adversario
	if (adversario->getId() == ID::jogador || adversario->getId() == ID::hydra || adversario->getId() == ID::fantasma) {
		 adv = static_cast<Personagens*>(adversario);
	}

	adv->perdeVida(dano);


}

void Projetil::Executar()
{
	if(visivel)
		movGravidade();

}

void Projetil::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	//Quando colide eu chamo o atacar (que causa dano no adversario)
	atacar(entidade, dano);

	//Volto para a estado inicial
	estadoInicial();
}
