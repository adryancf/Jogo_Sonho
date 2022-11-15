#include "Dragao.h"

Dragao::Dragao(): Inimigo(), tempo_de_ataque(1.0)
{
    //Forma Dragao
    corpo.setSize(Vector2f(50.f, 100.f));
    corpo.setFillColor(Color::Red);
    corpo.setPosition(Vector2f(500.f, 150.f));
    
    //Atributos Dragao
    setVelocidade(Vector2f(1.0f, 0.f));
    setQuantidadeVida(3);

    //Enquanto nao tem o enum dos ids
    ID = 10;

}

Dragao::~Dragao()
{
}

const float Dragao::getTempoAtaque() const
{
    return tempo_de_ataque;
}

void Dragao::Mover()
{
    //Aplica a gravidade
    movGravidade();
    movAleatorio();

}

void Dragao::Executar()
{
    verificaVida();
    Mover();
}
