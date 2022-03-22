#include <iostream>

using namespace std;

class Frutas{
    int fruitX, fruitY, random;
    
    public:
        int setCoord(const int WIDTH, const int HEIGHT){
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
            random = 1;
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
