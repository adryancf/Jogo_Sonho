#pragma once

#include "stdafx.h"

template<class TIPO>
class Lista
{
private:
	template <class TE>
	class Elemento
	{
	private:
		Elemento<TE>* pProx;
		Elemento<TE>* pAnterior;
		TE* pInformacao;

	public:
		Elemento()
		{
			pProx = nullptr;
			pAnterior = nullptr;
			pInformacao = nullptr;
		}
		~Elemento()
		{
			pProx = nullptr;
			pAnterior = nullptr;
			pInformacao = nullptr;
		}
		//Define o prox Elemento
		void setProx(Elemento<TE>* pProx)
		{
			this->pProx = nullptr;
		}
		//Retorna o prox elemento da lista
		Elemento<TE>* getProx()
		{
			return pProx;
		}
		//Define o elemento anterior da lista
		void setAnterior(Elemento<TE>* pAnterior)
		{
			this->pAnterior = pAnterior;
		}
		//Retorna o anterior
		Elemento<TE>* getAnterior()
		{
			return pAnterior;
		}
		void setInformacao(TE* pInformacao)
		{
			return pInfo;
		}
		TE* getInfo()
		{
			return pInformacao;
		}
	};

	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pUltimo;
	int tamanho;

public:
	Lista();
	~Lista();

	void limpar();
	void anexar(TIPO* pInformacao);
	int getTam()
	{
		return tamanho;
	}

	TIPO* operator[](int x);
	bool remover(TIPO* pTipo);

private:
	void setElemento(Elemento<TIPO>* pElemento);
	Elemento<TIPO>* getPrimeiro()
	{
		return pPrimeiro;
	}
	Elemento<TIPO>* getUltimo()
	{
		return pUltimo;
	}
};

template <class TIPO>
Lista<TIPO>::Lista() : pPrimeiro(), pUltimo(), tamanho(0)
{
	limpar();
}

template <class TIPO>
Lista<TIPO>::~Lista()
{
	clear();
}

template <class TIPO>
void Lista<TIPO>::limpar()
{
	Elemento<TL>* pAux1;
	Elemento<TL>* pAux2;

	pAux1 = pPrimeiro;
	pAux2 = pAux1;

	while (pAux1 != nullptr)
	{
		delete pAux1->getInfo();
		pAux2 = pAux1->getProx();
		delete pAux1;
		pAux1 = pAux2;
		--tamanho;
	}

	pPrimeiro = nullptr;
	pUltimo = nullptr;
}

template <class TIPO>
void Lista<TIPO>::setElemento(Elemento<TIPO>* pElemento)
{
	if (pElemento != nullptr)
	{
		if (pPrimeiro == nullptr)
		{
			pPrimeiro = pElemento;
			pUltimo = pElemento;
		}
		else
		{
			pUltimo->setNext(pElemento);
			pElemento->setAnterior(pUltimo);
			pUltimo = pElemento;
		}
		++tamanho;
	}
}

template <class TIPO>
void Lista<TIPO>::anexar(TIPO* pInfo) {
	if (pInfo != nullptr) {
		Elemento<TIPO>* pElemento = nullptr;
		pElemento = new Elemento<TIPO>();
		pElemento->setInformacao(pInfo);
		setElemento(pElemento);
	}
}

template <class TIPO>
TIPO* Lista<TIPO>::operator[](int x) {
	if (x >= tamanho || x < 0) {
		std::cout << "ERROR: Segmentation fault LISTAS." << std::endl;
		exit(1);
	}

	Elemento<TIPO>* pAux = pPrimeiro;
	for (int i = 0; i < x; i++) {
		pAux = pAux->getProx();
	}

	if (pAux == nullptr) {
		cout << "ERROR: on template operator[] pAux == NULL." << endl;
		exit(1);
	}
	return pAux->getInfo();
}

template <class TIPO>
bool Lista<TIPO>::remover(TIPO* pTL) {
	Elemento<TIPO>* pAux = pPrimeiro;
	Elemento<TIPO>* pPrev = nullptr;
	while (pAux != nullptr) {
		if (pAux->getInfo() == pTL) {
			if (pAux == pPrimeiro)
				pPrimeiro = pAux->getProx();
			else
				pPrev->setProx(pAux->getProx());
			delete (pAux);
			--size;
			return true;
		}
		pPrev = pAux;
		pAux = pAux->getProx();
	}
	return false;
}