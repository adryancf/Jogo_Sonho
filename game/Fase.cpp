#include "Fase.h"

Fase::Fase(Jogador *j): numero_instancias(0), j1(j), 
	plataforma_fase(nullptr), 
	caixa(nullptr), 
	ativa(true), 
	hydra(nullptr),
	pColisoes(nullptr),
	lista_obstaculos(nullptr),
	lista_personagem(nullptr)
{}

Fase::~Fase()
{
	//Aterrando ponteiros
	lista_obstaculos = nullptr;
	lista_personagem = nullptr;
	j1 = nullptr;
}

int Fase::gerarNumeroAleatorio(int min, int max)
{
	//Muda a seed
	//std::srand(std::time(nullptr));
	return (min + (std::rand() % (max - min + 1)));;
}

int Fase::gerarNumeroAleatorio(float min, float max)
{
	//Muda a seed
	//std::srand(std::time(nullptr));

	int max_int = static_cast<int>(max);
	int min_int = static_cast<int>(min);

	int numero = min_int + (std::rand() % (max_int - min_int + 1));

	return (numero);
}

void Fase::verificaTerminoFase()
{
	ativa = lista_personagem->verificaEntidadesVisiveis();
}

const bool Fase::getAtiva()
{
	return ativa;
}

void Fase::criarLista()
{
	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_personagem = new ListaEntidades;
	lista_obstaculos = new ListaEntidades;

	lista_personagem->incluir(j1);

	//Gerenciador
	pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

}

void Fase::deletaListas()
{
	if (pColisoes != nullptr)
		delete pColisoes;

	/*
	if (lista_personagem) {
		cout << "Deletando lista_personagens..." << endl;
		lista_personagem->removerTudo();
		//delete lista_personagem;
		lista_personagem = nullptr;
	}
	if (lista_obstaculos) {
		cout << "Deletando lista_obstaculos..." << endl;
		lista_obstaculos->removerTudo();
		//delete lista_obstaculos;
		lista_obstaculos = nullptr;
	
	}
	*/
}

ListaEntidades* Fase::getListaPersonagem()
{
	if (lista_personagem)
		return lista_personagem;
	else
		return nullptr;
}

ListaEntidades* Fase::getListaObstaculo()
{
	if (lista_obstaculos)
		return lista_obstaculos;
	else
		return nullptr;
}




