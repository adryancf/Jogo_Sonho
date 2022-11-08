#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define RESOLUCAO_X 1280
#define RESOLUCAO_Y 720

/* PADRAO DE PROJETO SINGLETON */
//Esse padrão de projeto consiste em garantir que a classe GerenciadorGrafico só tenha uma instância
//Uma construtora privada -> NENHUMA OUTRA CLASSE CONSEGUE INSTANCIAR ESSA CLASSE
//um método publico de acesso -> GARANTO UM ÚNICO PONTO GLOBAL DE ACESSO DA CLASSE (LOGICA QUE GARANTE O SINGLETON: IF atributo == NULL -> new atributo)
//um atributo estatico da própria classe

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

