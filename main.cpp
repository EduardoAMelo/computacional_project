#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "cenarios.h"
#include "cobra.h"
#include "jogador.h"
#include "ranking.h"
#define WIDTH 50
#define HEIGHT 25

using namespace std;

int main(){
    Jogador usuario[100];
    int menu;
    int quantidade_jogadores = 0;
    fstream ranking;
    string str;
    string carac;
    bool gameOver = false;
    Snake cobra(WIDTH, HEIGHT, gameOver);
    int xposition, yposition;
    xposition = cobra.getX();
    yposition = cobra.getY();

    ranking.open("ranking txt", ios::in);//abre arquivo para leitura

    while(getline(ranking,str)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		for(unsigned int i = 0; i <= str.size(); i++){
			if(carac[i] == '\n'){//quando o caractere for igual a quebra de linha quer dizer que um jogador foi cadastrado no arquivo
				quantidade_jogadores += 1;
            }
        }
    }

    cout << "Menu de opcoes" << endl;
    cout << "Aperte 1 para jogar" << endl;
    cout << "Aperte 2 para ver o ranking" << endl;
    cout << "Aperte 3 para ver as instrucoes de como jogar" << endl;
    cout << "Aperte 4 para sair do jogo" << endl;
    cin >> menu;

    while (menu != 4)
    {

        if (menu == 1)
        {
            usuario[quantidade_jogadores].Cadastra();
            while (!gameOver){
                main_scenario(xposition, yposition, WIDTH, HEIGHT);
                cobra.Input();
                cobra.Logic();
                xposition = cobra.getX();
                yposition = cobra.getY();

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
            }  
        }

        if (menu == 2)
        {
            if (quantidade_jogadores > 0)
            {
                Rank();//chama a funcao rank caso o arquivo tenha pelo menos um jogador
            }
            else{
                cout << "Ainda nao ha jogadores no Ranking" << endl;//caso nao tenha jogadores ele imprime a mensagem no terminal
            }
        }
        
        if (menu == 3)
		{
        	cout << "Use a tecla w para mover a cobrinha pra cima" << endl;	
        	cout << "Use a tecla a para mover a cobrinha pra esquerda" << endl;
        	cout << "Use a tecla d para mover a cobrinha pra a direita" << endl;
        	cout << "Use a tecla s para mover a cobrinha pra baixo" << endl;
        	cout << "O objetivo do jogo e pegar a maior quantidade de frutas possiveis sem morrer" << endl;
        	cout << "O jogador perde se a cabeca da cobrinha bater em uma parte do corpo da cobrinha" << endl;
        	cout << "Apos o jogo a pontuacao e armazenada e voce pode comparar a sua pontuacao com a de outros jogadores"<< endl;
        	cout << "Boa Sorte" << endl;
		}
        
        if (menu == 4)
        {
            exit(4);//sai do programa
        }
        
        cout << "Menu de opcoes" << endl;
        cout << "Aperte 1 para jogar" << endl;
        cout << "Aperte 2 para ver o ranking" << endl;
        cout << "Aperte 3 para ver as instrucoes de como jogar" << endl;
        cout << "Aperte 3 para sair do jogo" << endl;
        cin >> menu;

    }
    
    ranking.close();

    system ("pause");

    return 0;
}