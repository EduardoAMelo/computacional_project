#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Frutas{// a classe frutas ainda nao esta completa ela vai possuir subclasses e listas com a selecao dos minigames
    int fruitX, fruitY, random;
    
    public:
        int setCoord(const int WIDTH, const int HEIGHT){
            srand (time (0));//necessario para se tornar realmente aleatorio
            //aleatoriadade das frutas
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;
            random = rand() % 6;
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
