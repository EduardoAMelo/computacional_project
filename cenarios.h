#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

int points = 0;

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
                // F - Fruta normal  S - Special   H - Hard  $ - Super Special
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
                    cout << "$";
                    break;

                default:
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

    // Cout dos pontos na parte inferior da tela
    cout << "Pontos:" << points;
}

//metodo do minigame
void minigame(bool *select, int *mod, int tail){
    int counter, totalBot = 0, totalPlayer = 0, resposta, randomico;
    int y;
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
        Sleep(1000);
        system("cls");

        //ifs que vao ser importantes para declarar o vencedor com mais pontos
        if(totalBot == 0 && totalPlayer == 0){
            cout << bancoDados[3] << endl;
            Sleep(1000);
            system("cls");
        }
        if(totalBot == 0 && totalPlayer == 1){
            cout << bancoDados[1] << endl;
            Sleep(1000);
            system("cls");
        }
        if(totalBot == 1 && totalPlayer == 0){
            cout << bancoDados[0] << endl;
            Sleep(1000);
            system("cls");
        }
        if(totalBot == 1 && totalPlayer == 1){
            cout << bancoDados[2] << endl;
            Sleep(1000);
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
        *mod = tail;
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
        // Consequencia
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
        y= tail ^ (tail >> 1);
        y = y ^ (y >> 2);
        y = y ^ (y >> 4);
        y = y ^ (y >> 8);
        y = y ^ (y >> 16);
        //checando a paridade para nunca ter valores impares divididos por 2
        if (y & 1)
            *mod = (tail+1)/2;
        *mod = tail/2;

        //Felicidade meu parceiro
        points += 200;
    }

    system("cls");
    
    //Fechando o minigame
    *select = false;
}



// Logica geral das pontuacoes
void setChanges(int random){
    switch (random)
                {
                case 0:
                    points += 10;
                    break;

                case 1:
                    points += 10;
                    break;
    
                case 2:
                    points += 10;
                    break;

                case 3:
                    points += 10;
                    break;

                case 4:
                    points += 100;
                    break;

                case 5:
                    points += 10;
                    break;

                case 6:
                    points += 10;
                    break;
                
                default:
                    points += 10;
                    break;
                }
}


//Jogo da memoria
void minigameTwo(bool *select, int *mod, int tail){
    int randomico, resposta, y;
    //todas as possiveis opcoes de local da variavel c
    string opcoes[] = { R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |   ______     | | | |     ______   | | | |  ________    | |
//  | |  |_   _ \    | | | |   .' ___  |  | | | | |_   ___ `.  | |
//  | |    | |_) |   | | | |  / .'   \_|  | | | |   | |   `. \ | |
//  | |    |  __'.   | | | |  | |         | | | |   | |    | | | |
//  | |   _| |__) |  | | | |  \ `.___.'\  | | | |  _| |___.' / | |
//  | |  |_______/   | | | |   `._____.'  | | | | |________.'  | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)", R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |   ______     | | | |  ________    | | | |     ______   | |
//  | |  |_   _ \    | | | | |_   ___ `.  | | | |   .' ___  |  | |
//  | |    | |_) |   | | | |   | |   `. \ | | | |  / .'   \_|  | |
//  | |    |  __'.   | | | |   | |    | | | | | |  | |         | |
//  | |   _| |__) |  | | | |  _| |___.' / | | | |  \ `.___.'\  | |
//  | |  |_______/   | | | | |________.'  | | | |   `._____.'  | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)", R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |     ______   | | | |   ______     | | | |  ________    | |
//  | |   .' ___  |  | | | |  |_   _ \    | | | | |_   ___ `.  | |
//  | |  / .'   \_|  | | | |    | |_) |   | | | |   | |   `. \ | |
//  | |  | |         | | | |    |  __'.   | | | |   | |    | | | |
//  | |  \ `.___.'\  | | | |   _| |__) |  | | | |  _| |___.' / | |
//  | |   `._____.'  | | | |  |_______/   | | | | |________.'  | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)", R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |     ______   | | | |  ________    | | | |   ______     | |
//  | |   .' ___  |  | | | | |_   ___ `.  | | | |  |_   _ \    | |
//  | |  / .'   \_|  | | | |   | |   `. \ | | | |    | |_) |   | |
//  | |  | |         | | | |   | |    | | | | | |    |  __'.   | |
//  | |  \ `.___.'\  | | | |  _| |___.' / | | | |   _| |__) |  | |
//  | |   `._____.'  | | | | |________.'  | | | |  |_______/   | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)", R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |  ________    | | | |   ______     | | | |     ______   | |
//  | | |_   ___ `.  | | | |  |_   _ \    | | | |   .' ___  |  | |
//  | |   | |   `. \ | | | |    | |_) |   | | | |  / .'   \_|  | |
//  | |   | |    | | | | | |    |  __'.   | | | |  | |         | |
//  | |  _| |___.' / | | | |   _| |__) |  | | | |  \ `.___.'\  | |
//  | | |________.'  | | | |  |_______/   | | | |   `._____.'  | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)", R"(
//   .----------------.   .----------------.   .----------------. 
//  | .--------------. | | .--------------. | | .--------------. |
//  | |  ________    | | | |     ______   | | | |   ______     | |
//  | | |_   ___ `.  | | | |   .' ___  |  | | | |  |_   _ \    | |
//  | |   | |   `. \ | | | |  / .'   \_|  | | | |    | |_) |   | |
//  | |   | |    | | | | | |  | |         | | | |    |  __'.   | |
//  | |  _| |___.' / | | | |  \ `.___.'\  | | | |   _| |__) |  | |
//  | | |________.'  | | | |   `._____.'  | | | |  |_______/   | |
//  | |              | | | |              | | | |              | |
//  | '--------------' | | '--------------' | | '--------------' |
//   '----------------'   '----------------'   '----------------'
)"};

//randomizer
srand (time (0));
randomico = rand() % 6;


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

    cout << R"(
        

//                     __                  __                      ______
//    ____  ____  ____/ /__     ___  _____/ /_____ _   ____       / ____/
//   / __ \/ __ \/ __  / _ \   / _ \/ ___/ __/ __ `/  / __ \     / /     
//  / /_/ / / / / /_/ /  __/  /  __(__  ) /_/ /_/ /  / /_/ /    / /___   
//  \____/_/ /_/\__,_/\___/   \___/____/\__/\__,_/   \____/     \____/   
//                                                                       
                                                         

    )" << endl; 
    Sleep(2000);
    system("cls");

//Logica do randomizer das artes ascii
for (int i = 0; i < 5; i++){
    cout << opcoes[randomico] << endl;
    if(i == 4){
        Sleep(400);
        break;
    }
    randomico = rand() % 6;
    Sleep(800);
}
    system("cls");

    //Local do input do usuario
    cout << randomico << endl;
    cout << R"(
        |------------------------------|
        |1- UM      2-DOIS    3-TRES   | 
        |------------------------------|
    )" << "\n" << "Sua alternativa: "; 
    cin >> resposta;
    system("cls");

    //Switch com a logica do jogo da memoria
    switch (resposta)
    {
    case 1:
        if(randomico == 0 || randomico == 1 || randomico == 4 || randomico == 5){
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
        // Consequencia
        *mod = tail + 10;
        }
        if(randomico == 2 || randomico == 3){
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
        y= tail ^ (tail >> 1);
        y = y ^ (y >> 2);
        y = y ^ (y >> 4);
        y = y ^ (y >> 8);
        y = y ^ (y >> 16);
        //checando a paridade par
        if (y & 1)
            *mod = (tail+1)/2;
        *mod = tail/2;

        // yey
        points += 200;
    }

        break;

    //o processo e repetido para as tres respostas possiveis do usuario
    case 2:
        if(randomico == 1 || randomico == 2 || randomico == 3 || randomico == 4){
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
        if(randomico == 0 || randomico == 5){
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
        y= tail ^ (tail >> 1);
        y = y ^ (y >> 2);
        y = y ^ (y >> 4);
        y = y ^ (y >> 8);
        y = y ^ (y >> 16);
        //checando a paridade
        if (y & 1)
            *mod = (tail+1)/2;
        *mod = tail/2;
        points += 200;
    }

        break;

    case 3:
        if(randomico == 0 || randomico == 2 || randomico == 3 || randomico == 5){
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
        if(randomico == 1 || randomico == 4){
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
        y= tail ^ (tail >> 1);
        y = y ^ (y >> 2);
        y = y ^ (y >> 4);
        y = y ^ (y >> 8);
        y = y ^ (y >> 16);
        //checando a paridade
        if (y & 1)
            *mod = (tail+1)/2;
        *mod = tail/2;
        points += 200;
    }

        break;

    }
    system("cls");
    

    //finalizando o minigame
    *select = false;

}

//resetador de pontos

int resetPoints(){
    points = 0;
    return points;
}


//getter dos pontos para utilizacao no .txt
int getPoints(){
    return points;
}