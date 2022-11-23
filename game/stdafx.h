#pragma once

//Biblioteca SFML
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"         
#include "SFML/System.hpp"

//Bibliotecas PADRAO	
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <math.h>
#include <cmath>
#include <string>


//Talvez seja interessante definir as caracteristicas padroes da janela, inimigos e etc aqui.

//DEF GRAVIDADE
#define GRAVIDADE 998.f

//DEF BORDAS
#define BORDA_X 1210.0
#define BORDA_Y 650.0

#define BORDA_ESQ 0.f
#define BORDA_DIR 1280.f

//RESOLUCAO
#define RESOLUCAO_X 1280
#define RESOLUCAO_Y 720


//TAMANHOS

#define JOGADOR_X 30.f
#define JOGADOR_Y 30.f

#define DRAGAO_X 10.f
#define DRAGAO_Y 30.f

#define HYDRA_X 16.f
#define HYDRA_Y 16.f

#define ANJO_X 30.f
#define ANJO_Y 70.f

#define ESPESSURA_PLATAFORMA_F1 20.f
#define ESPESSURA_PLATAFORMA_F2 25.f



//Using
using namespace std;
using namespace sf;