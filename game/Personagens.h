#pragma once
#include "Entidade.h"
#include "string"

class Personagens : public Entidade
{
protected:

    //Vida
    float q_vida;
    bool vivo;

    //Ataque
    float dano;
    bool atacou;

    //Controle do Movimento
    bool podeAndarDireita;
    bool olhandoDireita;
    bool podeAndarEsquerda;
    bool olhandoEsquerda;
    bool podeAndar;
    bool podePular;
    string direcaoMovimento;

public:
    Personagens(const int q_vida = 5.0);
    ~Personagens();

    //ATAQUE
    void setDano(float dano);
    const float getDano() const;
    virtual void atacar(Personagens* adversario, float dano); // Se precisar redefinir a funcao eu posso
    void setAtacou(bool ataque);
    bool getAtacou();

    //VIDA DO PERSONAGEM
    void setQuantidadeVida(float q);
    const float getQuantidadeVida();
    const bool getVida() const;
    void verificaVida();
    void perdeVida(); //Da para substituir essa funcao por uma sobrecarga de operador
    void perdeVida(float dano);

    //MOVIMENTO E PULO
    void movimentaEntidade(Vector2f mov, bool direcao);
    void setDirecaoMovimento(string direcao); // true = direita , false = esquerda
    const Vector2<bool> getOlhar();
    void verificaPodeAndar();
    void verificaPodeAndar(Vector2f pos);
    const Vector2<bool> getPodeAndar();
    void pular(double tam_pulo);
   
    //FUN��ES PRINCIPAIS
    virtual void Executar() = 0;
    virtual void Mover() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //Cada personagem atualiza a vida a sua maneira, neste momento comentada pq tem que alterar a classe toda
    //virtual void atualizarVida() = 0;
};

