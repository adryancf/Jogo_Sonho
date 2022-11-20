#pragma once
#include "stdafx.h"

/* PADRAO DE PROJETO SINGLETON */
//Esse padrão de projeto consiste em garantir que a classe GerenciadorGrafico só tenha uma instância
//Uma construtora privada -> NENHUMA OUTRA CLASSE CONSEGUE INSTANCIAR ESSA CLASSE
//um método publico de acesso -> GARANTO UM ÚNICO PONTO GLOBAL DE ACESSO DA CLASSE (LOGICA QUE GARANTE O SINGLETON: IF atributo == NULL -> new atributo)
//um atributo estatico da própria classe

class GerenciadorGrafico
{
private:
	
	//Janela do jogo (criada nessa classe)
	sf::RenderWindow* window;

	//Define qual regiao da tela eh vista
	sf::View view;

	//Define a textura
	std::map<const char*, sf::Texture*> texturaMapa;

	//Define a fonte
	sf::Font* fonte;

	/* Singleton */
	static GerenciadorGrafico* pGrafico;
	//Construtora PRIVADA
	GerenciadorGrafico();

public:
	~GerenciadorGrafico();
	//retorna um ponteiro para o gerenciador grafico
	static GerenciadorGrafico* getGerenciadorGrafico();

	//retorna um ponteiro para a janela
	sf::RenderWindow* getWindow();

	//eh a clear()
	void limpar();

	//eh a funcao render()
	void desenhar(sf::RectangleShape* corpo); //desenha o corpo
	void desenhar(sf::Text* text); //desenha um texto

	//eh a funcao display()
	void mostrar();

	//eh a funcao closeWindow()
	void fecharJanela();

	//retorna o tamanho da janela
	sf::Vector2u getWindowSize() const;

	//Define a regiao a ser observada
	void centerView(sf::Vector2f pos);

	//Esta funcao retorna uma textura
	sf::Texture* loadTexture(const char* path);
	//retorna a fonte
	sf::Font* getFont();

	//deleta todas as texturas usadas
	void deletaTexturas();
};

