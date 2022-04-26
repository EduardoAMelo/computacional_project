#include <iostream>
#include <conio.h>


class Snake{//pretendo transformar em metodo pois so existe uma cobra

    int x, y, nTail; //snake´s head location and tail size
    int tailX[100], tailY[100];
    enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};//WASD input declarion logic
    int width, height;
    bool over, select;
    direction dir;

    public:
        Snake(const int WIDTH, const int HEIGHT, bool gameOver){
            x = WIDTH / 2;
            y = HEIGHT / 2;
            nTail = 0;
            dir = STOP;
            width = WIDTH;
            height = HEIGHT;
            over = gameOver;
            select = false;
        }


        void Input()//inputs da cobra
        {
            if (_kbhit())
            {
                switch (_getch())
                {
                case 'a':
                    dir = LEFT;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 'w':
                    dir = UP;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'x':
                    over = true;
                    break;
                }
            }
        }

        void Logic(){//logica geral
            int prevX = tailX[0];
            int prevY = tailY[0];
            int prev2X, prev2Y;
            tailX[0] = x;
            tailY[0] = y;

            //logica do corpo seguir a cabeca
            for (int i = 1; i < nTail; i++)
            {
                prev2X = tailX[i];
                prev2Y = tailY[i];
                tailX[i] = prevX;
                tailY[i] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }
            switch (dir){ // selecting directions
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default:
                break;
            }

        //walls colision with snake
            if (x >= width)
                x = 0;
            else if
                (x < 0) x = width - 1;

            if (y >= height)
                y = 0;
            else if
                (y < 0) y = height - 1;
            
        //snake colision itself
            for (int i = 0; i < nTail; i++)
                if (tailX[i] == x && tailY[i] == y)
                    over = true;
        }

        int getX(){
            return x;
        }
        int getY(){
            return y;
        }

        bool isOver(){
            return over;
        }

        //logica para aumentar o tamanho da cobra ou ativar minigame
        int getTail(int fruitX, int fruitY, int random){
            if(x == fruitX && y == fruitY && random == 3){
                nTail += 1;//para nunca ter valor menor que 1 "para os minigames"
                select = true;
            }

            else if(x == fruitX && y == fruitY && random == 4){
                nTail+= 10;
                select = false;
            }

            else if(x == fruitX && y == fruitY){
                nTail++;
                select = false;
            }
            return nTail;
        }

        int *getXtail(){
            return tailX;
        }


        int *getYtail(){
            return tailY;
        }

        
        bool getSelect(){
            return select;
        }

        void setTail(int tail){
            nTail = tail;
        }
};
