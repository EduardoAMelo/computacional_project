#include <iostream>
#include <string>
#include <windows.h>
#include "cenarios.h"
#include "cobra.h"
#include "frutas.h"
#define WIDTH 50
#define HEIGHT 25

using namespace std;

int main(){
    bool gameOver = false;
    Frutas fruits;
    Snake cobra(WIDTH, HEIGHT, gameOver);
    int xposition, yposition, tailSize, *xtail, *ytail, fruitX, fruitY, randomN, vigia;
    xposition = cobra.getX();
    yposition = cobra.getY();
    fruits.setCoord(WIDTH, HEIGHT);
    fruitX = fruits.getFruitX();
    fruitY = fruits.getFruitY();
    randomN = fruits.getRand();
    tailSize = cobra.getTail(fruitX, fruitY);
    xtail = cobra.getXtail();
    ytail = cobra.getYtail();



    while (!gameOver){
        main_scenario(xposition, yposition, WIDTH, HEIGHT, tailSize, xtail, ytail, fruitX, fruitY, randomN);
        cobra.Input();
        cobra.Logic();
        fruitX = fruits.getFruitX();
        fruitY = fruits.getFruitY();
        tailSize = cobra.getTail(fruitX, fruitY);
        xtail = cobra.getXtail();
        ytail = cobra.getYtail();
        xposition = cobra.getX();
        yposition = cobra.getY();
        if(xposition == fruitX && yposition == fruitY)
            fruits.setCoord(WIDTH, HEIGHT);
        gameOver = cobra.isOver();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

    return 0;
}

