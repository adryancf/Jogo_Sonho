#pragma once
#include "Entidade.h"

class Personagens : public Entidade
{
protected:
    int q_vida;
    bool vivo;

    bool atacou;

    // CONTROLE DO MOVIMENTO
    bool podeAndarDireita;
    bool olhandoDireita;
    bool podeAndarEsquerda;
    bool olhandoEsquerda;
    bool podePular;

public:
    Personagens(const int q_vida = 5);
    ~Personagens();

    //ATAQUE
    void setAtacou(bool ataque);
    bool getAtacou();

    //VIDA DO PERSONAGEM
    void setQuantidadeVida(int q);
    const int getQuantidadeVida();
    const bool getVida() const;
    void verificaVida();
    void perdeVida(); //Da para substituir essa função por uma sobrecarga de operador

    //MOVIMENTO E PULO
    const Vector2<bool> getOlhar();
    void verificaPodeAndar();
    void verificaPodeAndar(Vector2f pos);
    const Vector2<bool> getPodeAndar();
    void pular(double tam_pulo);
   
    //FUNÇÕES PRINCIPAIS
    virtual void Executar() = 0;
    virtual void Mover() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //Cada personagem atualiza a vida a sua maneira, neste momento comentada pq tem que alterar a classe toda
    //virtual void atualizarVida() = 0;
};

