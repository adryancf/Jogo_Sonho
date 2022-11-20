#pragma once
#include "Ente.h"
//O botao eh tambem uma entidade

class Botao : public Ente
{
private:
	bool hover; //nao sei pra que que serve
	sf::Text text;
	sf::Font font;
	//sprite & texture
	sf::Sprite sprite;
	sf::Texture texture;
public:
	//Construtora/Destrutora
	Botao(sf::Vector2f pos); //seta  a pos do botao
	~Botao();
	Botao();

	//Inicializa a texture e depois a sprite
	void inicializarSprite();

	//mensagem
	void setMensagem(const char* m);
	void selecionar(const bool selecionado);
};

