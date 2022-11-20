#include "Botao.h"

Botao::Botao(sf::Vector2f pos) : hover(false)
{
}

Botao::~Botao() 
{
}

Botao::Botao() : hover(false)
{
}

void Botao::inicializarSprite()
{
	if (!texture.loadFromFile("assets/Button.png"))
	{
		std::cout << "Impossivel abrir a Button.png" << std::endl;
		exit(1);
	}

	sprite.setTexture(texture);


}

void Botao::setMensagem(const char* m)
{
}

void Botao::selecionar(const bool selecionado)
{
	hover = selecionado;
}
