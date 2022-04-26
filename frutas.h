#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Frutas{
    int fruitX, fruitY, random;
    
    public:
        int setCoord(const int WIDTH, const int HEIGHT){
            srand (time (0));//necessario para se tornar realmente aleatorio
            //aleatoriadade no spawn das frutas
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;

            // random e responsavel pela selecao da fruta que vai de 0 a 6
            random = rand() % 8;
        }


        // Metodos de getters essenciais para o funcionamento do jogo
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
