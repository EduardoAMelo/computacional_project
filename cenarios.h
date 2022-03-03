#include <iostream>
#include <string>


using namespace std;

void main_scenario(int x, int y, const int WIDTH, const int HEIGHT){
    // system("cls"); //clear console to create animation
    for(int i = 0; i < HEIGHT; i++){ //loops for creation of scenario
        cout << "\t\t#";

        for(int j = 0; j < WIDTH - 2; j++){
            if(i == 0 || i == HEIGHT-1)
                cout << "#";
            else if (i == y && j == x)
                cout << "@";
            else
                cout << " ";
        }

        cout << "#\n";

    }
}