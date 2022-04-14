#include <iostream>
#include <string>


using namespace std;

void main_scenario(int x, int y, const int WIDTH, const int HEIGHT, int nTail, int tailX[], int tailY[], int fruitX, int fruitY, int random){
    for (int i = 0; i < WIDTH+2; i++)
        cout << "#";
    cout << endl;
 
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "@";
            else if (i == fruitY && j == fruitX)
                switch (random)
                {
                case 0:
                    cout << "F";
                    break;

                case 1:
                    cout << "F";
                    break;

                case 2:
                    cout << "F";
                    break;

                case 3:
                    cout << "S";
                    break;

                case 4:
                    cout << "H";
                    break;

                case 5:
                    cout << "F";
                    break;

                case 6:
                    cout << "F";
                    break;

                case 7:
                    cout << "F";
                    break;
                }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < WIDTH+2; i++)
        cout << "#";
    cout << endl;
    // cout << "Score:" << score << endl;
}