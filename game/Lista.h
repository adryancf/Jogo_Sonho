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
		if (pPrimeiro != nullptr) {
			Elemento<TIPO>* aux1 = pPrimeiro;
			Elemento<TIPO>* aux2 = aux1;
			TIPO* aux3;

			while (aux1 != nullptr)
			{
				aux2 = aux1->getProximo();
				aux3 = aux1->getItem();

				delete aux1;
				delete aux3;

				aux1 = aux2;

			}
			pUltimo = nullptr;
			pPrimeiro = nullptr;
			tamanho = 0;
		}
	}

	Elemento<TIPO>* getUltimo() { return pUltimo; }
	Elemento<TIPO>* getPrimeiro() { return pPrimeiro; }

	const int getTamanho() { return tamanho; }

	TIPO* getItemLista(int posicao)
	{
		Elemento<TIPO>* aux = pPrimeiro;
		if (posicao == 0)
			return aux->getItem();
		else
		{
			//errado o jeito de andar 
			for (int i = 0; i < posicao; i++)
				aux = aux->getProximo();
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
			Elemento<TIPO>* aux = new Elemento<TIPO>();

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

