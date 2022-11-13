#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define RESOLUCAO_X 1280
#define RESOLUCAO_Y 720

/* PADRAO DE PROJETO SINGLETON */
//Esse padr�o de projeto consiste em garantir que a classe GerenciadorGrafico s� tenha uma inst�ncia
//Uma construtora privada -> NENHUMA OUTRA CLASSE CONSEGUE INSTANCIAR ESSA CLASSE
//um m�todo publico de acesso -> GARANTO UM �NICO PONTO GLOBAL DE ACESSO DA CLASSE (LOGICA QUE GARANTE O SINGLETON: IF atributo == NULL -> new atributo)
//um atributo estatico da pr�pria classe

class GerenciadorGrafico
{
private:
	
	sf::RenderWindow* window;

	/* Singlton */
	static GerenciadorGrafico* pGrafico;
	GerenciadorGrafico();
public:
	~GerenciadorGrafico();
	static GerenciadorGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();
	void limpar();
	void desenhar(sf::RectangleShape corpo);
	void mostrar();
	void fecharJanela();
	const bool isWindowOpen();




};

