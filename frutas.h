#include <iostream>

using namespace std;

class Frutas{
    int fruitX, fruitY, random;
    
    public:
        int setCoord(const int WIDTH, const int HEIGHT){
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
            random = rand() % 8;
        }

        int getFruitX(){
            return fruitX;
        }


        int getFruitY(){
            return fruitY;
        }

        int getRand(){
            return random;
        }
};