#pragma once
#include "Ente.h"

#define GRAVIDADE 998.0

//Borda para o movimento do jogador (o setPosition nao segue essas medidas, la é 1280x720)
#define BORDA_X 1210.0
#define BORDA_Y 650.0


enum ID
{
	eempty = 0,
	jogador,
	hydra,
	anjo,
	dragao,
	caixa,
	espinho,
	plataforma,
	inimigo,
	obstaculo
};


//derivando como virtual public
class Entidade : virtual public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;
 
	//UTIL PARA O CALCULO DA GRAVIDADE
	sf::Vector2f speed;

	ID id;
	//int ID;/

	bool colisao; //acho que nao preciso desse atributo
	bool colisaoPlataforma;
	bool colisaoCima;
	bool gravidade;
	bool noChao;
	bool emCima;
	bool isMoving;

public:

	//textura e sprite
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Sprite getSprite();



	//retorna o ID
	ID getId() const;

	Entidade(ID idd = eempty);
	~Entidade();

	//ATRIBUTOS
	void setVelocidade(Vector2f velocidade);
	Vector2f* getVelocidade();





	//CORPO
	RectangleShape getCorpo();
	void setColor(sf::Color cor);
	void setPosEntidade(Vector2f pos);
	void movimentaEntidade(Vector2f mov);

	//const int getId();
	const bool getisMoving();

	//COLISAO E GRAVIDADE
	void setColisao(bool a);
	void setColisaoPlataforma(bool a);
	void setDirecaoColisao(bool d);
	const bool getDirecaoColisao();

	void movGravidade();
	void corrigeColisoes(Entidade* a, Vector2f inter);
	//void verificaColisaoPlataforma(Entidade* e);
	
	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;
};

