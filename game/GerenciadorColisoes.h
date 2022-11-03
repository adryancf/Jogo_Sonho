#pragma once

#include "SFML/Graphics.hpp"
#include "ListaEntidades.h"

/** GERENCIADOR DE COLOSIOES
	
	FUNCIONAMENTO
	O gerenciador de colisões tem como objetivo Verificar a colisão entre duas entidades no Jogo.
	Seu funcionamento consiste na seguinte formula:
	
	colisao x = |(posicao x1 - posicao x2)| - (tamanho1/2 - tamanho2/2) 
	colisao y = |(posicao x1 - posicao x2)| - (tamanho1/2 - tamanho2/2)

	Se a colisao x e colisao y < 0 -> OBJETOS ESTAO EM COLISAO

*/


class GerenciadorColisoes
{

private:
	ListaEntidades* lista_entidades;

public:
	GerenciadorColisoes(ListaEntidades* l1);
	~GerenciadorColisoes();

	sf::Vector2f calculaColisoes();
	bool verificaColisoes();


};

