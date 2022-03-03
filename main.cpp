#include <iostream>
#include <string>
#include <windows.h>
#include "cenarios.h"
#include "cobra.h"
#define WIDTH 50
#define HEIGHT 25

using namespace std;

int main(){
    bool gameOver = false;
    Snake cobra(WIDTH, HEIGHT, gameOver);
    int xposition, yposition;
    xposition = cobra.getX();
    yposition = cobra.getY();

    while (!gameOver){
        main_scenario(xposition, yposition, WIDTH, HEIGHT);
        cobra.Input();
        cobra.Logic();
        xposition = cobra.getX();
        yposition = cobra.getY();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

    return 0;
}

