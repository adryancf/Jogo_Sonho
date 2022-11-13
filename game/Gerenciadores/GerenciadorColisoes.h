#pragma once

#include "SFML/Graphics.hpp"
#include "Listas/ListaEntidades.h"
#include "Ente/Entidades/Personagens/Personagens.h"

#include <utility>
#include <cmath>

class GerenciadorColisoes
{

private:
	ListaEntidades* lista_obstaculos;
	ListaEntidades* lista_personagens;

public:
	GerenciadorColisoes(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos);
	~GerenciadorColisoes();

	sf::Vector2f calculaColisoes(Entidade* ent1, Entidade* ent2);
	void verificaColisoes();


};

//Referencias
/*
Código com base no video do monitor Giovane: youtube.com/watch?v=B5zPLK9nuGw&list=PLR17O9xbTbIBBoL3lli44N8LdZVvg-_uZ&index=7
*/

//GERENCIADOR DE COLOSIOES (Explicação)
/*

	FUNCIONAMENTO
	O gerenciador de colisões tem como objetivo Verificar a colisão entre duas entidades no Jogo.
	Seu funcionamento consiste na seguinte formula:

	colisao x = |distancia entre os centros| - (soma das metades do tamanho)
	colisao y = |(distancia entre os centros)| - (soma das metades do tamanho)

	Se a soma das metades dos tamanhos é menor que a distância entre os centros, os elementos estao em colisao no eixo analisado!
	Ou seja, se essa diferença for negativa, há colisão

	O objeto só esta em colisão de fato quando os dois eixos se encontram
	Ou seja, colisao x < 0 e colisao y < 0 -> COLISAO!!!!!

*/
