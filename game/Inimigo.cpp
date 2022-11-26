
#include "Inimigo.h"


Inimigo::Inimigo():Personagens(), tempo_mov(), player1(nullptr), player2(nullptr), jogadorEmCima(false)

{   
    movRandom = rand() % 4; //SEED FALTANTE
    id = ID::inimigo; // ARRUMAR ID
}


Inimigo::~Inimigo()
{
	player1 = nullptr;
	player2 = nullptr;
}


void Inimigo::movAleatorio()
{
    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 0.5s */
    if (noChao || emCimaEntidade) {
        if (movRandom == 0) {
            movimentaEntidade(Vector2f(speed.x, 0.f), true);
        }
        else if (movRandom == 1) {
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);
        }
    }
    
    float dt = tempo_mov.getElapsedTime().asSeconds();
    if (dt >= 1.0f) {
        movRandom = rand() % 2;
        tempo_mov.restart();
    }

}

void Inimigo::qualPerseguir(Vector2f pos_j1, Vector2f pos_j2, Vector2f pos_inimigo)
{
	Vector2f proximidadeJogador1;
	proximidadeJogador1.x = fabs(pos_j1.x - pos_inimigo.x);
	proximidadeJogador1.y = fabs(pos_j1.y - pos_inimigo.y);

	Vector2f proximidadeJogador2;
	proximidadeJogador2.x = fabs(pos_j2.x - pos_inimigo.x);
	proximidadeJogador2.y = fabs(pos_j2.y - pos_inimigo.y);

	if (proximidadeJogador1.x <= proximidadeJogador2.x || proximidadeJogador1.y <= proximidadeJogador2.y)
	{
		podePerseguir(player1);
		if (proximidadeJogador1.x <= raio_deteccao.x && proximidadeJogador1.y <= raio_deteccao.y && podeAndar) {

			PersegueJogador(pos_j1, pos_inimigo);
		}
	}
	else
	{
		podePerseguir(player2);
		if (proximidadeJogador2.x <= raio_deteccao.x && proximidadeJogador2.y <= raio_deteccao.y && podeAndar) {

			PersegueJogador(pos_j2, pos_inimigo);
		}
	}
}

Personagens* Inimigo::verificaMaisProximo(Jogador* j1, Jogador* j2, Vector2f pos_inimigo)
{

	Vector2f pos_j1 = j1->getPosicao();
	Vector2f pos_j2 = j2->getPosicao();

	Vector2f proximidadeJogador1;
	proximidadeJogador1.x = fabs(pos_j1.x - pos_inimigo.x);
	proximidadeJogador1.y = fabs(pos_j1.y - pos_inimigo.y);

	Vector2f proximidadeJogador2;
	proximidadeJogador2.x = fabs(pos_j2.x - pos_inimigo.x);
	proximidadeJogador2.y = fabs(pos_j2.y - pos_inimigo.y);

	if (proximidadeJogador1.x <= proximidadeJogador2.x || proximidadeJogador1.y <= proximidadeJogador2.y)
	{
		return j1;
	}
	else
		return j2;

}

void Inimigo::PersegueJogador(Vector2f posJogador, Vector2f posInimimgo)
{

	//funçao altera as flags 
	Vector2f diferenca = posJogador - posInimimgo;

	if ((diferenca.x > 0)) {
		movimentaEntidade(Vector2f(speed.x, 0.0), true);
	}

	else if ((diferenca.x < 0))
	{
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

void Inimigo::podePerseguir(Personagens* personagem)
{
	bool podeAndarPersonagem;

	if (olhandoDireita) {

		personagem->verificaPodeAndar(repulsao_direita);
		podeAndarPersonagem = personagem->getPodeAndarDireita();

		if (podeAndarPersonagem)
			podeAndar = true;
		else if (!podeAndarPersonagem)
			podeAndar = false;
	}
	else if (olhandoEsquerda) {
		
		personagem->verificaPodeAndar(repulsao_esquerda);
		podeAndarPersonagem = personagem->getPodeAndarEsquerda();

		if (podeAndarPersonagem)
			podeAndar = true;
		else if (!podeAndarPersonagem)
			podeAndar = false;
	}
}

