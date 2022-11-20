#include "GerenciadorEventos.h"

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento():
    pGrafico(GerenciadorGrafico::getGerenciadorGrafico()), 
    Jogador1(nullptr),
    tecla_pres(0)
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
    else if (tecla == sf::Keyboard::A) {
        Jogador1->andar(2);
        tecla_pres = 1;
    }
    else if (tecla == sf::Keyboard::D) {
        Jogador1->andar(4);
        tecla_pres = 2;
    }
    else if(tecla == sf::Keyboard::Space){ //pulando muito baixo
        Jogador1->pular(0.008);
    }
    else if (tecla == sf::Keyboard::W)
    {
        Jogador1->pular(0.03);
    }
    /*
    if (tecla_pres == 1)
        Jogador1->andar(2);

    if (tecla_pres == 2)
        Jogador1->andar(4);
 */           
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    //VERIFICAR SE A TECLA FOR SOLTA E ALTERAR A FLAG
    /*
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
        tecla_pres = 0;
        */

}

void GerenciadorEvento::Executar()
{
    //loop de execução da janela
    
    Event event;
    while (pGrafico->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            verificaTeclaPressionada(event.key.code);
        }
        /*else if (tecla_pres == 1)
            Jogador1->andar(2);

        else if (tecla_pres == 2)
            Jogador1->andar(4);
            */
        else if (event.type == Event::KeyReleased) {
            verificaTeclaSolta(event.key.code);
        }
        else if (event.type == Event::Closed) {
            pGrafico->fecharJanela();
        }
        
        

    }

}
