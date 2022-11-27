#include "Menu.h"

Menu::Menu() : Ente()
{
   
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

}

Menu::~Menu() 
{
    delete font;
    delete image;
    delete bg;
}


void Menu::draw_all() 
{
    pGrafico->limpar();
    pGrafico->desenhar(*bg);

    for (auto t : texts) {
        pGrafico->desenhar(t);
    }

    pGrafico->mostrar();

}

void Menu::run_menu() {
    while (pGrafico->isWindowOpen() && pGrafico->getEstado() == ID::menuPrincipal)
    {
        loop_events();
        draw_all();
    }
}

void Menu::Executar()
{
    run_menu();
}
