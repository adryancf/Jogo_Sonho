#include "Jogo.h"
#include "Menu.h"
#include <conio.h>
int main()
{
    Menu* menu = new Menu();
    menu->run_menu();
    getch();
    //Jogo jogo;
    //jogo.Executar();

    return 0;
}