#include "GerenciadorGrafico.h"

#define RESOLUCAO_X 1280
#define RESOLUCAO_Y 720


GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;
float GerenciadorGrafico::dt = 0;

GerenciadorGrafico::GerenciadorGrafico(): estado(ID::menuPrincipal), umJogador(true), fase1(false),
    window(new sf::RenderWindow(sf::VideoMode(RESOLUCAO_X, RESOLUCAO_Y), "Sonho++")),
    clock()
{
    if (window == nullptr) {
        std::cout << "Nao foi possivel criar uma janela gráfica!" << std::endl;
        exit(1);
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window) {
        delete(window);
        window = nullptr;
    }

}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGrafico == nullptr) {
        pGrafico = new GerenciadorGrafico;
    }

    return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpar()
{
    window->clear();
}

void GerenciadorGrafico::desenhar(sf::RectangleShape corpo)
{
    window->draw(corpo);
}

void GerenciadorGrafico::desenhar(sf::Sprite corpo)
{
    window->draw(corpo);
}

void GerenciadorGrafico::desenhar(sf::Text t)
{
    window->draw(t);
}

/*
void GerenciadorGrafico::desenhar(sf::Sprite p)
{
    window->draw(p);
}

void GerenciadorGrafico::desenhar(sf::Text t)
{
    window->draw(t);
}
*/
void GerenciadorGrafico::mostrar()
{
    window->display();
}

void GerenciadorGrafico::fecharJanela()
{
    window->close();
}

const bool GerenciadorGrafico::isWindowOpen()
{
    return window->isOpen();
}

const bool GerenciadorGrafico::verificaEventos(sf::Event evento)
{
    return (window->pollEvent(evento));
}



void GerenciadorGrafico::atualizaTempo()
{
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();

}

void GerenciadorGrafico::setEstado(const ID id)
{
    estado = id;
}

const ID GerenciadorGrafico::getEstado() const
{
    return estado;
}

void GerenciadorGrafico::setUmJogador(bool t)
{
    this->umJogador = t;
}

const bool GerenciadorGrafico::getUmJogador() const
{
    return umJogador;
}

void GerenciadorGrafico::setFase1(bool t)
{
    fase1 = t;
}

const bool GerenciadorGrafico::getFase1() const
{
    return fase1;
}

