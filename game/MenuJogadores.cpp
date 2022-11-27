#include "MenuJogadores.h"
MenuJogadores::MenuJogadores() : Ente(), window(pGrafico->getWindow())
{
    //std::cout << "Construtora menu iniciada." << std::endl;
    //window = new sf::RenderWindow();
    //winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

MenuJogadores::~MenuJogadores() {
    // delete window;
     //delete winclose;
    delete font;
    delete image;
    delete bg;
}

void MenuJogadores::set_values() {
    //window->create(sf::VideoMode(1280, 720), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
    //window->setPosition(sf::Vector2i(0, 0));
    //std::cout << "Setando os valores do menu" << std::endl;
    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("assets/Fonts/PixelFont2.ttf");
    image->loadFromFile("assets/menu.png");

    bg->setTexture(*image);

    //pos_mouse = { 0,0 };
    //mouse_coord = { 0, 0 };

    options = { "Sonho++", "1 Jogador", "2 Jogadores", "Aleatório", "Voltar" };
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

    //std::cout << "Valores do menu setados." << std::endl;
}
void MenuJogadores::loop_events() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
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
void MenuJogadores::draw_all() {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void MenuJogadores::run_menu() {
    while (window->isOpen() && pGrafico->getEstado() == ID::menuJogadores)
    {
        loop_events();
        draw_all();
    }
}
void MenuJogadores::Executar()
{
    run_menu();
    //draw_all();
}
