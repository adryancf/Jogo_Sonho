#include "Entidade.h"

Entidade::Entidade(ID idD, sf::Vector2f posicaoO, sf::Vector2f hit) : Ente(idD, posicaoO), hitbox(hit)
{
    velocidade = sf::Vector2f(0.f, 0.f); //nao eh necessario inicializar velocidade pq o  Vector ja faz isso
    showing = false; //inicialmente nao esta mostrando em tela
}

Entidade::Entidade() : Ente()
{
    velocidade = sf::Vector2f(0.f, 0.f);
    hitbox = sf::Vector2f(0.f, 0.f);
    showing = false;
}

Entidade::~Entidade()
{
}

void Entidade::setVelocidade(sf::Vector2f vel)
{
    velocidade = vel;
}

sf::Vector2f Entidade::getVelocidade()
{
    return velocidade;
}

void Entidade::setHitbox(sf::Vector2f hit)
{
    hitbox = hit;
}

sf::Vector2f Entidade::getHitbox()
{
    return hitbox;
}

void Entidade::setShowing(bool s)
{
    showing = s;
}

bool Entidade::getShowing()
{
    return showing;
}
