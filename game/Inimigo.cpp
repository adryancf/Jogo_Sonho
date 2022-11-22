
#include "Inimigo.h"


Inimigo::Inimigo():Personagens(), tempo_mov(), player(nullptr)
{   
    movRandom = rand() % 4; //SEED FALTANTE
    id = ID::inimigo; // ARRUMAR ID
}


Inimigo::~Inimigo()
{
	player = nullptr;
}


void Inimigo::movAleatorio()
{
    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 0.5s */
    if (noChao) {
        if (movRandom == 1) {
            movimentaEntidade(Vector2f(speed.x, 0.f), true);
        }
        else if (movRandom == 2) {
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);
        }
    }
    
    float dt = tempo_mov.getElapsedTime().asSeconds();
    if (dt >= 0.5f) {
        movRandom = rand() % 4;
        tempo_mov.restart();
    }

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
	Vector2<bool> podeAndarPersonagem;

	if (olhandoDireita) {

		if (repulsao.x < 0.0)
			repulsao.x *= -1.0;

		personagem->verificaPodeAndar(repulsao);
		podeAndarPersonagem = personagem->getPodeAndar();

		if (podeAndarPersonagem.x)
			podeAndar = true;
		else if (!podeAndarPersonagem.x)
			podeAndar = false;
	}
	else if (olhandoEsquerda) {

		if(repulsao.x > 0.0)
			repulsao.x *= -1.0;
		
		personagem->verificaPodeAndar(repulsao);
		podeAndarPersonagem = personagem->getPodeAndar();

		if (podeAndarPersonagem.y)
			podeAndar = true;
		else if (!podeAndarPersonagem.y)
			podeAndar = false;
	}
}

