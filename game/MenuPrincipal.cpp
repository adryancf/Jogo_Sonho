#include "MenuPrincipal.h"


MenuPrincipal::MenuPrincipal()
{
    set_values();

}
MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::run_menu()
{
    while (pGrafico->isWindowOpen() && pGrafico->getEstado() == ID::menuPrincipal)
    {
        loop_events();
        draw_all();
    }
}

void MenuPrincipal::set_values()
{
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("assets/Fonts/PixelFont2.ttf");
    image->loadFromFile("assets/menu.png");

    bg->setTexture(*image);

    options = { "Jogo", "Fase1", "Fase2", "Leaderboard", "Quit" };
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

void MenuPrincipal::loop_events()
{
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
            //Quit
            if (pos == 4) {
                pGrafico->fecharJanela();
            }
            //Iniciar jogo
            else if (pos == 1)
            {
                pGrafico->setEstado(ID::menuJogadores);
                pGrafico->setFase1(true);
            }
            //Inicia a fase2
            else if (pos == 2)
            {
                pGrafico->setEstado(ID::menuJogadores);
                pGrafico->setFase1(false);

            }
            //Leaderboard
            else if (pos == 3)
            {
                pGrafico->setEstado(ID::leaderboard);

            }

            std::cout << options[pos] << '\n';
        }
    }
}