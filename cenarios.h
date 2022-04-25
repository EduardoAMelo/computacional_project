#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

//banco de dados das pontuacoes utilizadas no minigame
string bancoDados[] = { R"(
//   .----------------.  .----------------.  .----------------. 
//  | .--------------. || .--------------. || .--------------. |
//  | |     ____     | || |  ____  ____  | || |     __       | |
//  | |   .'    '.   | || | |_  _||_  _| | || |    /  |      | |
//  | |  |  .--.  |  | || |   \ \  / /   | || |    `| |      | |
//  | |  | |    | |  | || |    > `' <    | || |     | |      | |
//  | |  |  `--'  |  | || |  _/ /'`\ \_  | || |    _| |_     | |
//  | |   '.____.'   | || | |____||____| | || |   |_____|    | |
//  | |              | || |              | || |              | |
//  | '--------------' || '--------------' || '--------------' |
//   '----------------'  '----------------'  '----------------' 
)", R"(
//   .----------------.  .----------------.  .----------------. 
//  | .--------------. || .--------------. || .--------------. |
//  | |     __       | || |  ____  ____  | || |     ____     | |
//  | |    /  |      | || | |_  _||_  _| | || |   .'    '.   | |
//  | |    `| |      | || |   \ \  / /   | || |  |  .--.  |  | |
//  | |     | |      | || |    > `' <    | || |  | |    | |  | |
//  | |    _| |_     | || |  _/ /'`\ \_  | || |  |  `--'  |  | |
//  | |   |_____|    | || | |____||____| | || |   '.____.'   | |
//  | |              | || |              | || |              | |
//  | '--------------' || '--------------' || '--------------' |
//   '----------------'  '----------------'  '----------------' 
)", R"(
//   .----------------.  .----------------.  .----------------. 
//  | .--------------. || .--------------. || .--------------. |
//  | |     __       | || |  ____  ____  | || |     __       | |
//  | |    /  |      | || | |_  _||_  _| | || |    /  |      | |
//  | |    `| |      | || |   \ \  / /   | || |    `| |      | |
//  | |     | |      | || |    > `' <    | || |     | |      | |
//  | |    _| |_     | || |  _/ /'`\ \_  | || |    _| |_     | |
//  | |   |_____|    | || | |____||____| | || |   |_____|    | |
//  | |              | || |              | || |              | |
//  | '--------------' || '--------------' || '--------------' |
//   '----------------'  '----------------'  '----------------' 
)", R"(
//   .----------------.  .----------------.  .----------------. 
//  | .--------------. || .--------------. || .--------------. |
//  | |     ____     | || |  ____  ____  | || |     ____     | |
//  | |   .'    '.   | || | |_  _||_  _| | || |   .'    '.   | |
//  | |  |  .--.  |  | || |   \ \  / /   | || |  |  .--.  |  | |
//  | |  | |    | |  | || |    > `' <    | || |  | |    | |  | |
//  | |  |  `--'  |  | || |  _/ /'`\ \_  | || |  |  `--'  |  | |
//  | |   '.____.'   | || | |____||____| | || |   '.____.'   | |
//  | |              | || |              | || |              | |
//  | '--------------' || '--------------' || '--------------' |
//   '----------------'  '----------------'  '----------------' 
)"};


//metodo do main scenario que faz o desenho no terminal
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
            else if (i == fruitY && j == fruitX)//localizacao e tipo de fruta sendo desenhados
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
                }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)//localizacao e corpo da cobra sendo desenhados
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

//metodo do minigame
void minigame(bool *select, int *mod, int tail){
    int counter, totalBot = 0, totalPlayer = 0, resposta, randomico;
    srand (time (0));
    randomico = rand() % 3;
    string names[] = {"Pedra", "Papel", "Tesoura"};//array que segura os 3 tipos de resposta

    //array que segura as ascii arts de mao
    string respostas[] = {R"(   
     _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___))", R"(   
      _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________))", R"(    
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___))" };

//ascii arte de quando a fruta s e pega
    cout << R"(
        
//   ________  ________  ________   ___  ___  ________      
//  |\   __  \|\   __  \|\   ___  \|\  \|\  \|\   ____\     
//  \ \  \|\ /\ \  \|\  \ \  \\ \  \ \  \\\  \ \  \___|_    
//   \ \   __  \ \  \\\  \ \  \\ \  \ \  \\\  \ \_____  \   
//    \ \  \|\  \ \  \\\  \ \  \\ \  \ \  \\\  \|____|\  \  
//     \ \_______\ \_______\ \__\\ \__\ \_______\____\_\  \ 
//      \|_______|\|_______|\|__| \|__|\|_______|\_________\
//                                              \|_________|
//                                                          
//                                                          

    )" << endl; 
    Sleep(800);
    system("cls");

    for(counter = 0; counter < 3; counter++){//minigame rodando até 3 vezes
        //escolha das alternativas
        randomico = rand() % 3;

        cout << R"(
            |------------------------------|
            |1- Pedra   2-Papel   3-Tesoura|
            |------------------------------|
        )" << "\n" << "Sua alternativa: "; 
        cin >> resposta;
        system("cls");
        switch (resposta)//switch com a logica do pedra, papel e tesoura
        {
        case 1:
            if(randomico == 0){
                cout << "EMPATE!!!" << endl;
            }
            if(randomico == 1){
                cout << "ROUND PERDIDO!!!" << endl;
                totalBot++;
            }
            if(randomico == 2){
                cout << "ROUND GANHO!!!" << endl;
                totalPlayer++;
            } 
  
            break;

        case 2:
            if(randomico == 0){
                cout << "ROUND GANHO!!!" << endl;
                totalPlayer++;
            }
            if(randomico == 1){
                cout << "EMPATE!!!" << endl;
            }
            if(randomico == 2){
                cout << "ROUND PERDIDO!!!" << endl;
                totalBot++;
            }
            break;

        case 3:
            if(randomico == 0){
                cout << "ROUND PERDIDO!!!" << endl;
                totalBot++;
            }
            if(randomico == 1){
                cout << "ROUND GANHO!!!" << endl;
                totalPlayer++;
            }
            if(randomico == 2){
                cout << "EMPATE!!!" << endl;
            }
            break;
        }
        //cout dos resultados
        cout << "Sua resposta é " << names[resposta - 1] << "\n" << respostas[resposta - 1] << endl;
        cout << "Robo escolheu " << names[randomico] << "\n" << respostas[randomico] << endl;
        Sleep(2000);
        system("cls");

        //ifs que vao ser importantes para declarar o vencedor com mais pontos
        if(totalBot == 0 && totalPlayer == 0){
            cout << bancoDados[3] << endl;
            Sleep(2000);
            system("cls");
        }
        if(totalBot == 0 && totalPlayer == 1){
            cout << bancoDados[1] << endl;
            Sleep(2000);
            system("cls");
        }
        if(totalBot == 1 && totalPlayer == 0){
            cout << bancoDados[0] << endl;
            Sleep(2000);
            system("cls");
        }
        if(totalBot == 1 && totalPlayer == 1){
            cout << bancoDados[2] << endl;
            Sleep(2000);
            system("cls");
        }
        if(totalBot == 2 || totalPlayer == 2){
            break;
        }    

    }

//ascii arts dos resultados
    if(totalBot == totalPlayer){
        cout << R"(
//   _______   _____ ______   ________  ________  _________  _______      
//  |\  ___ \ |\   _ \  _   \|\   __  \|\   __  \|\___   ___\\  ___ \     
//  \ \   __/|\ \  \\\__\ \  \ \  \|\  \ \  \|\  \|___ \  \_\ \   __/|    
//   \ \  \_|/_\ \  \\|__| \  \ \   ____\ \   __  \   \ \  \ \ \  \_|/__  
//    \ \  \_|\ \ \  \    \ \  \ \  \___|\ \  \ \  \   \ \  \ \ \  \_|\ \ 
//     \ \_______\ \__\    \ \__\ \__\    \ \__\ \__\   \ \__\ \ \_______\
//      \|_______|\|__|     \|__|\|__|     \|__|\|__|    \|__|  \|_______|
//                                                                        
//                                                                        
//                                                                        
)";
        Sleep(4000);
    }
    if(totalBot > totalPlayer){
        cout << R"(
//   ________  ________  ________          ________  ________  ________  _________  _______      
//  |\   __  \|\   __  \|\   __  \        |\   ____\|\   __  \|\   __  \|\___   ___\\  ___ \     
//  \ \  \|\ /\ \  \|\  \ \  \|\  \       \ \  \___|\ \  \|\  \ \  \|\  \|___ \  \_\ \   __/|    
//   \ \   __  \ \  \\\  \ \   __  \       \ \_____  \ \  \\\  \ \   _  _\   \ \  \ \ \  \_|/__  
//    \ \  \|\  \ \  \\\  \ \  \ \  \       \|____|\  \ \  \\\  \ \  \\  \|   \ \  \ \ \  \_|\ \ 
//     \ \_______\ \_______\ \__\ \__\        ____\_\  \ \_______\ \__\\ _\    \ \__\ \ \_______\
//      \|_______|\|_______|\|__|\|__|       |\_________\|_______|\|__|\|__|    \|__|  \|_______|
//                                           \|_________|                                        
//                                                                                               
//                                                                                               
)";
        Sleep(4000);
        *mod = tail + 10;

    }
    if(totalBot < totalPlayer){
        cout << R"(
//   ________  ________  _______   _____ ______   ___  ________  ________  ________     
//  |\   __  \|\   __  \|\  ___ \ |\   _ \  _   \|\  \|\   __  \|\   ___ \|\   __  \    
//  \ \  \|\  \ \  \|\  \ \   __/|\ \  \\\__\ \  \ \  \ \  \|\  \ \  \_|\ \ \  \|\  \   
//   \ \   ____\ \   _  _\ \  \_|/_\ \  \\|__| \  \ \  \ \   __  \ \  \ \\ \ \  \\\  \  
//    \ \  \___|\ \  \\  \\ \  \_|\ \ \  \    \ \  \ \  \ \  \ \  \ \  \_\\ \ \  \\\  \ 
//     \ \__\    \ \__\\ _\\ \_______\ \__\    \ \__\ \__\ \__\ \__\ \_______\ \_______\
//      \|__|     \|__|\|__|\|_______|\|__|     \|__|\|__|\|__|\|__|\|_______|\|_______|
//                                                                                      
//                                                                                      
//                                                                                      
)";
        Sleep(4000);
        *mod = round(tail/2);

    }

    system("cls");
    *select = false;
}