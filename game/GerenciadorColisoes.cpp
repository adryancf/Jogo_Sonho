#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos)
{
	lista_personagens = l_personagem;
	lista_obstaculos = l_obstaculos;

}

GerenciadorColisoes::~GerenciadorColisoes()
{
	//Acho que vou destruir eles na classe jogo, onde sao instanciados
		
}

sf::Vector2f GerenciadorColisoes::calculaColisoes(Entidade* e1, Entidade* e2)
{
	sf::Vector2f colisao;

	sf::Vector2f pos1 = e1->getCorpo().getPosition();
	sf::Vector2f pos2 = e2->getCorpo().getPosition();

	sf::Vector2f tam1 = e1->getCorpo().getSize();
	sf::Vector2f tam2 = e2->getCorpo().getSize();

	//Modulo da distancia entre os centros dos elementos menos a soma da metade do tamanho
	colisao.x = fabs((pos1.x + (tam1.x/2.0f)) - (pos2.x + (tam2.x/2.0f))) - 
				((tam1.x / 2.0f) + (tam2.x / 2.0f));

	colisao.y = fabs((pos1.y + (tam1.y / 2.0f)) - (pos2.y + (tam2.y / 2.0f))) -
		((tam1.y / 2.0f) + (tam2.y / 2.0f));

	

	return colisao;
}

void GerenciadorColisoes::verificaColisoes()
{

	

	//COLISAO ENTRE PERSONAGEM E JOGADOR (FAZER ISSO)
	Personagens* Jogador1 = static_cast <Personagens*>(lista_personagens->listEnt.getPrimeiro()->getItem());
	for (int j = 1; j < lista_personagens->listEnt.getTamanho(); j++) {
		Entidade* aux2 = lista_personagens->listEnt.getItemLista(j);
		sf::Vector2f Colisao = calculaColisoes(Jogador1, aux2);
		if (Colisao.x < 0.0f && Colisao.y < 0.0f) {
			Jogador1->setColisao(true);
			aux2->setColisao(true);
			Jogador1->Colisao(aux2);
		}
		else {
			Jogador1->setColisao(false);
			aux2->setColisao(false);
		}
	}

	//O pair transforma dois tipos em um so
	vector <pair<Entidade*, Entidade*>> vector_colisoes;

	//Verifico a colisão entre os personagens e os obstaculos
	for (int i = 0; i < lista_personagens->listEnt.getTamanho(); i++)
	{
		bool colidiu_com_algo = false;
		Entidade* aux1 = lista_personagens->listEnt.getItemLista(i);

		for (int j = 0; j < lista_obstaculos->listEnt.getTamanho(); j++) {
			Entidade* aux2 = lista_obstaculos->listEnt.getItemLista(j);

			Vector2f Colisao = calculaColisoes(aux1, aux2);

			if (Colisao.x < 0.0f && Colisao.y < 0.0f) 
			{
				vector_colisoes.push_back(make_pair(aux1, aux2));
			}
		
			aux1->setColisao(false);
			aux2->setColisao(false);
			
		}


	}

	for (int i = 0; i < vector_colisoes.size(); i++) {

		vector_colisoes[i].first->setColisao(true);
		vector_colisoes[i].second->setColisao(true);
		vector_colisoes[i].first->Colisao(vector_colisoes[i].second);
	}

	
	/*
	//Verifico a colisão entre os personagens
	for (int i = 0; i < lista_personagens->listEnt.getTamanho(); i++)
	{
		Entidade* aux1 = lista_personagens->listEnt.getItem(i);
		for (int j = i+1; j < lista_personagens->listEnt.getTamanho(); j++) {
			Entidade* aux2 = lista_personagens->listEnt.getItem(j);
			sf::Vector2f Colisao = calculaColisoes(aux1, aux2);
			if (Colisao.x < 0.0f && Colisao.y < 0.0f)
				return true;
		}
	}
	*/
	
}
