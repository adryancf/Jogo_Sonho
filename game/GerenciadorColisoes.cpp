#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(ListaEntidades* pLista) : lista(pLista)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
	lista = nullptr;
}

//Essa função corre toda a lista e causa as colisoes
void GerenciadorColisoes::colidir()
{
	Entidade* ent1, * ent2;

	for (auto i = 0; i < lista->getTamanho(); ++i)
	{
		for (auto j = i + 1; j < lista->getTamanho(); ++j)
		{
			ent1 = (*lista)[i];
			ent2 = (*lista)[j];
			if (ent1->getShowing() && ent2->getShowing())
			{
				bool atk = ((ent1->getId() == ID::jogador && (ent2->getId() == ID::hydra || ent2->getId() == ID::dragao || ent2->getId() == ID::anjo))
					|| (ent2->getId() == ID::jogador && (ent1->getId() == ID::hydra || ent1->getId() == ID::dragao || ent1->getId() == ID::anjo)));

				float dy, dx, intersectX, intersectY;
				dx = ent2->getPosicao().x - ent1->getPosicao().x;
				dy = ent2->getPosicao().y - ent1->getPosicao().y;

				intersectX = abs(dx) - (ent1->getHitbox().x / 2 + ent2->getHitbox().x / 2);
				intersectY = abs(dy) - (ent1->getHitbox().y / 2 + ent2->getHitbox().y / 2);

				if (atk)
				{
					atacarJogador(ent1, ent2, dx, dy);
				}
				if (intersectX < 0.0f && intersectY < 0.0f)
				{
					if (ent1->getId() == ID::jogador || ent1->getId() == ID::jogador2) {
						colidirJogador(ent1, ent2, dx, dy, intersectX, intersectY);
					}
					else if (ent1->getId() == ID::dragao || ent1->getId() == ID::hydra || ent1->getId() == ID::anjo) {
						colidirInimigo(ent1, ent2, dx, dy, intersectX, intersectY);
					}
					else if (ent1->getId() == ID::projetil) {
						colidirProjetil(ent1, ent2, dx, dy, intersectX, intersectY);
					}
					else if (ent1->getId() == ID::plataforma || ent1->getId() == ID::parede) {
						colidirPlataforma(ent1, ent2, dx, dy, intersectX, intersectY);
					}
				}
			}
		}
	}
}

void GerenciadorColisoes::setLista(ListaEntidades* pLista)
{

}
