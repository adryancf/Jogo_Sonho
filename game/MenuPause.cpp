#include "MenuPause.h"

MenuPause::MenuPause() : Menus::Menu()
{
    set_values();

}

MenuPause::~MenuPause() {
    
}

void MenuPause::run_menu()
{
    while (pGrafico->isWindowOpen() && pGrafico->getEstado() == ID::menuPause)
    {
        loop_events();
        draw_all();
    }
}

void MenuPause::set_values()
{
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("assets/Fonts/PixelFont2.ttf");
    image->loadFromFile("assets/menu.png");

    bg->setTexture(*image);

    options = { "Sonho++", "Continuar", "...", "...", "Quit" };
    texts.resize(5);
    coords = { {590,40},{620,191},{610,282},{590,370},{623,457} };
    sizes = { 20,28,24,24,24 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;
}

void MenuPause::loop_events() {
    sf::Event event;
    while (pGrafico->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            pGrafico->fecharJanela();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {

            theselect = true;

            //Volta para o menuPrincipal
            if (pos == 4) {
                pGrafico->setEstado(ID::menuPrincipal);
            }

            //Simplesmente continua o jogo
            else if (pos == 1)
            {
                if (pGrafico->getFase1() == true)
                    pGrafico->setEstado(ID::fase1);
                else
                    pGrafico->setEstado(ID::fase2);
            }
            //faz nada por hora
            else if (pos == 2)
            {
                //pGrafico->setEstado(ID::menuJogadores);
                pGrafico->fecharJanela();

            }
            //faz nada por hora
            else if (pos == 3)
            {
                //pGrafico->setEstado(ID::leaderboard);
                pGrafico->fecharJanela();
            }

            std::cout << options[pos] << '\n';
        }
    }
}


