#include "MenuJogadores.h"

MenuJogadores::MenuJogadores() : Menu()
{
    set_values();

}

MenuJogadores::~MenuJogadores() {
    
}

void MenuJogadores::run_menu()
{
    while (pGrafico->isWindowOpen() && pGrafico->getEstado() == ID::menuJogadores)
    {
        loop_events();
        draw_all();
    }
}

void MenuJogadores::set_values()
{
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("assets/Fonts/PixelFont2.ttf");
    image->loadFromFile("assets/menu.png");

    bg->setTexture(*image);

    //pos_mouse = { 0,0 };
    //mouse_coord = { 0, 0 };

    options = { "Sonho++", "1 Jogador", "2 Jogadores", "Aleatorio", "Voltar" };
    texts.resize(5);
    coords = { {590,40},{590,191},{590,282},{590,370},{623,457} };
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

void MenuJogadores::loop_events() {
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
            //Volta ao menuPrincipal
            if (pos == 4) {
                pGrafico->setEstado(ID::menuPrincipal);
            }
            //Inicia a fase com 1 jogador
            else if (pos == 1)
            {
                if (pGrafico->getFase1() == true)
                    pGrafico->setEstado(ID::fase1);
                else
                    pGrafico->setEstado(ID::fase2);

                pGrafico->setUmJogador(true);
            }
            //Inicia a fase com 2 jogadores
            else if (pos == 2)
            {
                if (pGrafico->getFase1() == true)
                    pGrafico->setEstado(ID::fase1);
                else
                    pGrafico->setEstado(ID::fase2);

                pGrafico->setUmJogador(false);
            }
            //Numero aleatorio de jogadores 1 ou 2
            else if (pos == 3)
            {
                pGrafico->setEstado(ID::aleatorio);

            }

            std::cout << options[pos] << '\n';
        }
    }
}

