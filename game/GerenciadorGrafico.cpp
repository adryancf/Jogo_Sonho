#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;

GerenciadorGrafico::GerenciadorGrafico() :
window(new sf::RenderWindow(sf::VideoMode(RESOLUCAO_X, RESOLUCAO_Y), "Jogo C++")),
view(sf::Vector2f(RESOLUCAO_X / 2, RESOLUCAO_Y / 2), sf::Vector2f(RESOLUCAO_X, RESOLUCAO_Y)), texturaMapa()
{
    window->setFramerateLimit(120);
    fonte = nullptr;
}

void GerenciadorGrafico::mostrar()
{
    //Confere se a janela esta aberta e faz o display
    if (window->isOpen())
        window->display();
}

void GerenciadorGrafico::fecharJanela()
{
    window->close();
}

sf::Vector2u GerenciadorGrafico::getWindowSize() const
{
    return window->getSize();
}

void GerenciadorGrafico::centerView(sf::Vector2f pos)
{
    //define a visualizacao e faz a janela apontar pra view
    view.setCenter(pos);
    window->setView(view);
}

sf::Texture* GerenciadorGrafico::loadTexture(const char* path)
{
    std::map<const char*, sf::Texture*>::iterator it;
    for (it = texturaMapa.begin(); it != texturaMapa.end(); ++it)
    {
        if (!strcmp(it->first, path)) //strcmp retorna 0 se igual, entao !
            return it->second;
    }

    //se nao achou nada entao deve carregar a textura

    sf::Texture* textura = new sf::Texture(); //cria uma textura vazia

    if (!textura->loadFromFile(path))
    {
        std::cout << "Impossivel carregar a textura: " << path << std::endl;
        exit(1);
    }
    //Simplesmente insere no mapa o nome do caminho e a textura
    texturaMapa.insert(std::pair<const char*, sf::Texture*>(path, textura));
    return textura;
}

sf::Font* GerenciadorGrafico::getFont()
{
    //Retorna a fonte se ela ja existe
    //Cria a fonte se ela nao existe
    if (!fonte)
    {
        fonte = new sf::Font(); //define uma fonte vazia
        if (!fonte->loadFromFile("assets/minecraft-ten.ttf"))
        {
            std::cout << "Impossivel abrir a fonte: GerenciadorGrafico.cpp" << std::endl;
        }
    }
    return fonte;
}

void GerenciadorGrafico::deletaTexturas()
{
    //Simplesmente itera sobre o std::map e remove a textura
    std::map<const char*, sf::Texture*>::iterator it;
    for (it = texturaMapa.begin(); it != texturaMapa.end(); ++it)
        delete (it->second);
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGrafico == nullptr)
        pGrafico = new GerenciadorGrafico();
    return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpar()
{
    if (window->isOpen())
        window->clear();
}

void GerenciadorGrafico::desenhar(sf::RectangleShape* corpo)
{
    window->draw(*corpo);
}

void GerenciadorGrafico::desenhar(sf::Text* text)
{
    window->draw(*text);
}

