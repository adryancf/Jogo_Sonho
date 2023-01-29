#pragma once
#include "Ente.h"

/* Referencias */
//Implementação Baseada nesse video: https://www.youtube.com/watch?v=h8-Q4eu3Qt4&t=1169s

namespace Menus {
	class Menu : public Ente
	{
	protected:
		//Como eh derivado do ENTE jah tem o posicao
		int pos;
		bool pressed, theselect;

		//A fonte
		sf::Font* font;
		//A textura
		sf::Texture* image;
		//A sprite
		sf::Sprite* bg;
		//Guarda as coordenadas do mouse
		sf::Vector2i pos_mouse;
		sf::Vector2i mouse_coord;

		//As opções em tela
		std::vector<const char*> options; //Os nomes no menu
		std::vector<sf::Vector2f> coords;
		//Utilizada para renderizar os textos
		std::vector<sf::Text> texts;
		std::vector<std::size_t> sizes;


		void draw_all();

		//CADA MENU DERIVADO REDEFINE ESSA FUNÇÃO
		virtual void set_values() = 0;
		virtual void loop_events() = 0;
	public:
		Menu();
		virtual ~Menu();
		virtual void run_menu() = 0;

		//redefinindo a executar
		void Executar();
	};
}
