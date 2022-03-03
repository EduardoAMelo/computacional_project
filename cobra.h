#include <iostream>
#include <conio.h>


class Snake{

    int x, y, tail_size; //snake´s head location and tail size
    int tailX[100], tailY[100];//array of locations for snake body
    enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};//WASD input declarion logic
    int width, height;
    bool over;
    direction dir;

    public:
        Snake(const int WIDTH, const int HEIGHT, bool gameOver){
            x = WIDTH / 2;
            y = HEIGHT / 2;
            tail_size = 0;
            dir = STOP;
            width = WIDTH;
            height = HEIGHT;
            over = gameOver;
        }


        void Input()
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

        void Logic(){
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
        }

        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};
