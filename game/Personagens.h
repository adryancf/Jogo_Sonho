#pragma once
#include "Entidade.h"

class Personagens : public Entidade
{
protected:
    int q_vida;

    // CONTROLE DO MOVIMENTO
    bool podeAndarDireita;
    bool olhandoDireita;
    bool podeAndarEsquerda;
    bool olhandoEsquerda;

public:
    Personagens(const int q_vida = 5);
    ~Personagens();

    void setQuantidadeVida(int q);
    const int getVida() const;


    //Verifica se o Personagem pode Andar
    void verificaPodeAndar();
   
    virtual void Executar() = 0;
    virtual void Mover() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //metodo -> atualizar vida (implementar)
    //Cada personagem atualiza a vida a sua maneira, neste momento comentada pq tem que alterar a classe toda
    //virtual void atualizarVida() = 0;
};

