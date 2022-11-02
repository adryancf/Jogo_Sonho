#include "GerenciadorEventos.h"

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento():
    pGrafico(GerenciadorGrafico::getGerenciadorGrafico()), 
    Jogador1(nullptr)
{
}

GerenciadorEvento::~GerenciadorEvento()
{
    if (pEvento) {
        delete(pEvento);
        pEvento = nullptr;
    }
    if (pGrafico) {
        delete(pGrafico);
        pGrafico = nullptr;
    }
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
    if (pEvento == nullptr) {
        return pEvento = new GerenciadorEvento;
    }

    return pEvento;
}

void GerenciadorEvento::setJogador(Jogador* j)
{
    this->Jogador1 = j;
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    if (tecla == sf::Keyboard::Escape) {
        pGrafico->fecharJanela();
    }
    else if (tecla == sf::Keyboard::W) {
        Jogador1->andar(1);
    }
    else if (tecla == sf::Keyboard::A) {
        Jogador1->andar(2);
    }
    else if (tecla == sf::Keyboard::S) {
        Jogador1->andar(3);
    }
    else if (tecla == sf::Keyboard::D) {
        Jogador1->andar(4);
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{

}

void GerenciadorEvento::Executar()
{
    //loop de execução da janela
    
    Event event;
    while (pGrafico->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed){
            verificaTeclaPressionada(event.key.code);
        }
        else if (event.type == Event::KeyReleased){
            verificaTeclaSolta(event.key.code);
        }
        else if (event.type == Event::Closed) {
            pGrafico->fecharJanela();
        }
      

    }

}
