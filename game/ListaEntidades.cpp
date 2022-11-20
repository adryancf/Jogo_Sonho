#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() : lista()
{
}

ListaEntidades::~ListaEntidades()
{
	lista.limpar();
}

//Percorre a lista e atualiza cada entidade
void ListaEntidades::attTudo(float deltaTime)
{
	Entidade* pAux;
	for (auto i = 0; i < lista.getTam(); ++i)
	{
			pAux = lista[i];
			pAux->update(deltaTime);
	}
}

//Renderiza tudo que está na lista
void ListaEntidades::renderTudo()
{
	Entidade* pAux;
	for (auto i = 0; i < lista.getTam(); ++i)
	{
		if (lista[i]->getShowing())
		{
			pAux = lista[i];
			pAux->render();
		}
	}
}

//Adiciona a lista o pE se nao for vazio
void ListaEntidades::adicionar(Entidade* pE)
{
	if (pE == nullptr)
	{
		std::cout << "Ponteiro pE é o nullptr. Checar ListaEntidades::adicionar" << std::endl;
		exit(2);
	}
	lista.anexar(pE);
}

//Recebe um ponteiro para entiadde pE e remove se não for o nullptr
void ListaEntidades::remover(Entidade* pE)
{
	if (pE == nullptr)
	{
		std::cout << "Imposível remover nullptr. Checar ListaEntidades::remover." << std::endl;
		exit(3);
	}
	lista.remover(pE);
}

//Remove tudo o que há na lista
void ListaEntidades::removerTudo()
{
	lista.limpar();
}

void ListaEntidades::removerTudoExcetoJogador()
{
	for (auto i = 0; i < lista.getTam(); ++i)
	{
		if ((lista[i]->getId() != ID::jogador) || (lista[i]->getId() != ID::jogador2))
		{
			lista.remover(lista[i]);
		}
	}
}

Entidade* ListaEntidades::operator[](int x)
{
	if (x >= lista.getTam() || x < 0)
	{
		std::cout << "Erro. Checar ListaEntidades::operator[]" << std::endl;
		exit(4);
	}
	Entidade* pAux = lista[x];
	return pAux;
}

//Retorna o tamanho da lista
int ListaEntidades::getTamanho()
{
	return lista.getTam();
}
