#include "Projetil.h"

Projetil::Projetil():portador(nullptr), repouso(true), t()
{
	//Forma Projetil
	corpo.setSize(Vector2f(10.f, 5.f));
	corpo.setFillColor(Color::Red);

	//Atributos Projetil
	setVelocidade(Vector2f(5.0f, 0.f));
	dano = 2.f;

	id = ID::projetil;

	estadoInicial();

}


Projetil::~Projetil()
{
	
	if (portador)
		portador = nullptr;

}
void Projetil::verificarBordas()
{
	Vector2f posProjetil = getPosicao();

	if (posProjetil.x < 0.f || 
		posProjetil.x > RESOLUCAO_X || 
		posProjetil.y < 0.f ||
		posProjetil.y > RESOLUCAO_Y)
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



void Projetil::atacar(Entidade* adversario, float dano)
{

	//Quando colidir eu chamo essa funcao que ataca o adversario
	if (adversario->getId() == ID::jogador) {

		Personagens* adv = static_cast<Personagens*>(adversario);
		adv->perdeVida(dano);
	}

}

//Passar o tempo de ataque aqui
void Projetil::atirar(string direcao, float tempo)
{

	tempo_ataque = t.getElapsedTime().asSeconds();
	cout << tempo_ataque << endl;

	if (repouso && tempo_ataque >= tempo) {

		t.restart();

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
	verificarBordas();

	//Sempre atualiza a posicao da entidade
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
		//atacar(entidade, dano);
	}

	//Volto para a estado inicial
	estadoInicial();
}
