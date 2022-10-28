#pragma once

#include "Elemento.h"

template<class TIPO>
class Lista
{

private:
	Elemento<TIPO>* pUltimo;
	Elemento<TIPO>* pPrimeiro;

	int tamanho;

public:

	Lista() { pUltimo = nullptr; pPrimeiro = nullptr; tamanho = 0; }
	~Lista()
	{
	}

	const Elemento<TIPO>* getUltimo() { return pUltimo; }
	const Elemento<TIPO>* getPrimeiro() { return pPrimeiro; }

	const int getTamanho() { return tamanho; }

	TIPO* getItem(int posicao)
	{
		Elemento<TIPO>* aux = pPrimeiro;
		if (posicao == 0)
			return aux->getItem();
		else
		{
			for (int i = 0; i < posicao; i++)
				aux = pPrimeiro->getProximo();
			return aux->getItem();

		}


	}

	void push(TIPO* add)
	{
		if (pPrimeiro == nullptr) {
			pPrimeiro = new Elemento<TIPO>;

			pPrimeiro->setItem(add);
			pUltimo = pPrimeiro;

		}

		else
		{
			Elemento<TIPO>* aux = new Elemento<TIPO>;

			aux->setItem(add);
			pUltimo->setProximo(aux);
			pUltimo = aux;
		}
		tamanho++;
	}

	void pop(TIPO* e_remove)
	{
		Elemento<TIPO>* aux = pPrimeiro;
		Elemento<TIPO>* auxAnt = nullptr;

		while (aux->getItem() != e_remove)
		{
			auxAnt = aux;
			aux = aux->getProximo();
		}

		if (aux == pPrimeiro)
			pPrimeiro = aux->getProximo();

		else if (aux == pUltimo) {
			aux->setProximo(nullptr);
			pUltimo = auxAnt;
		}

		else
		{
			auxAnt->setProximo(aux->getProximo());
		}

		delete aux;
		tamanho--;
	}
};

