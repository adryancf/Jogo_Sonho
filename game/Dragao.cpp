#include "Dragao.h"

Dragao::Dragao(): Inimigo(), tempo_de_ataque(1.0)
{
    //Forma Dragao
    corpo.setSize(Vector2f(25.f, 70.f));
    corpo.setFillColor(Color::Red);
    
    //Atributos Dragao
    setVelocidade(Vector2f(1.0f, 0.f));
    setQuantidadeVida(3);

    //Enquanto nao tem o enum dos ids
    id = ID::dragao;

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
