#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "cenarios.h"
#include "cobra.h"
#include "jogador.h"
#include "ranking.h"
#include "frutas.h"
#define WIDTH 50
#define HEIGHT 25

using namespace std;

int main(){
    // todas as declaracoes da main
    Jogador usuario[100];
    int menu;
    int quantidade_jogadores = 0;
    fstream ranking;
    string str;
    string caractere;
    bool gameOver = false, select = false, *changeSel, game;
    changeSel = &select;
    Frutas fruits;
    Snake cobra(WIDTH, HEIGHT, gameOver);
    int xposition, yposition, tailSize, *xtail, *ytail, fruitX, fruitY, randomN, *tailmod, minigTail, totalpoints = getPoints();

    // Valores Iniciais para a cobra
    xposition = cobra.getX();
    yposition = cobra.getY();
    fruits.setCoord(WIDTH, HEIGHT);
    fruitX = fruits.getFruitX();
    fruitY = fruits.getFruitY();
    randomN = fruits.getRand();
    tailSize = cobra.getTail(fruitX, fruitY, randomN);
    tailmod = &minigTail;
    xtail = cobra.getXtail();
    ytail = cobra.getYtail();
    
    // Cout dos menus
    cout << "Menu de opcoes" << endl;
    cout << "Aperte 1 para jogar" << endl;
    cout << "Aperte 2 para ver o ranking" << endl;
    cout << "Aperte 3 para ver as instrucoes de como jogar" << endl;
    cout << "Aperte 4 para sair do jogo" << endl;
    cin >> menu;
    cout << "\n";

    // Loop do Menu
    while (menu != 4)
    {
        gameOver = false;
        ranking.open("ranking.txt",ios::in);//abre arquivo para leitura
            if (!ranking.is_open())//se o arquivo nao for aberto ele imprime a mensagem de erro
            {
                cerr<<"Erro"<<endl;
            }
            while(getline(ranking,str)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		        for(unsigned int f = 0; f <= str.size(); f++){
			        if(str[f] == '.'){//quando o caractere da string for igual ao ponto final quer dizer que um jogador foi cadastrado no arquivo
                        quantidade_jogadores += 1;
                    } 
                }
            }

            ranking.close();

        if (menu == 1)
        {
            if (quantidade_jogadores == 100)//quando a quantidade de jogadores dentro do arquivo txt chegar a 100 e o usuario quiser jogar denovo a contagem de usuarios recomeca 
            {
                ranking.open ("ranking.txt",ios::out | ios::trunc);//abre o arquivo e apaga o conteudo que esta dentro
                quantidade_jogadores = 0;//a contagem recomeca
                ranking.close();
                
            }

            ranking.open("ranking.txt",ios::app);//abre o arquivo e escreve abaixo

            usuario[quantidade_jogadores].Cadastra();
            system("cls");
            while(!gameOver){//While geral que controla o inicio e fim do game
                while (!select){//while do cenario principal
                    main_scenario(xposition, yposition, WIDTH, HEIGHT, tailSize, xtail, ytail, fruitX, fruitY, randomN);
                    //logica da cobra
                    cobra.Input();
                    cobra.Logic();
                    fruitX = fruits.getFruitX();
                    fruitY = fruits.getFruitY();
                    xtail = cobra.getXtail();
                    ytail = cobra.getYtail();
                    xposition = cobra.getX();
                    yposition = cobra.getY();
                    
                    //logica da randomizacao da fruta e da cobra comendo a fruta especial
                    if(xposition == fruitX && yposition == fruitY){
                        tailSize = cobra.getTail(fruitX, fruitY, randomN);
                        setChanges(randomN);
                        fruits.setCoord(WIDTH, HEIGHT);
                        randomN = fruits.getRand();
                        select = cobra.getSelect();
                        game = cobra.getGame();
                    }
                    //trigger do gameover
                    gameOver = cobra.isOver();
                    if(gameOver)
                        break;

                    // Setador de pontos
                    totalpoints = getPoints();
                    usuario[quantidade_jogadores].setPontos(totalpoints);

                    //codigo para dar refresh na tela mais suave pois system("cls") é muito ruim
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
                }
                system("cls");
                if (select){//trigger do minigame 
                        // Jokenpo
                        if(game)  
                            minigame(changeSel, tailmod, tailSize);
                        
                        // Jogo da Memoria
                        if (!game)  
                            minigameTwo(changeSel, tailmod, tailSize);
                        
                        //Logica para não ocorrer a perca de pontos ao perder a calda (vencedores)
                        cobra.setTail(minigTail);
                        tailSize = minigTail;
                        //codigo para dar refresh na tela mais suave pois system("cls") é muito ruim
                        system("cls");
                }
            }
            if(gameOver){//Logica para dar um reset na cobra
                gameOver = cobra.setDir(WIDTH, HEIGHT);
                totalpoints = resetPoints();
                cobra.Logic();    
            }
            //apos o jogador perder, o seu nome e sua pontuacao sao registradas no ranking
            ranking << usuario[quantidade_jogadores].getNick() << " " << usuario[quantidade_jogadores].getPontos() << "." <<endl;
            system ("pause");
            system ("cls");
        }

        ranking.close(); 

        if (menu == 2)
        {
            if (quantidade_jogadores > 0)
            {
                Rank();//chama a funcao rank caso o arquivo tenha pelo menos um jogador
            }
            else{
                cout << "Ainda nao ha jogadores no Ranking" << endl;//caso nao tenha jogadores ele imprime a mensagem no terminal
            }
            cout << "\n";
            system ("pause");
            system ("cls");
        }
        
        if (menu == 3)
		{
            // Tutorial geral
        	cout << "Use a tecla w para mover a cobrinha pra cima" << endl;	
        	cout << "Use a tecla a para mover a cobrinha pra esquerda" << endl;
        	cout << "Use a tecla d para mover a cobrinha pra a direita" << endl;
        	cout << "Use a tecla s para mover a cobrinha pra baixo" << endl;
        	cout << "O objetivo do jogo e pegar a maior quantidade de frutas possiveis sem morrer" << endl;
            cout << "Existem frutas especiais que podem te ajudar durante o jogo" << endl;
        	cout << "O jogador perde se a cabeca da cobrinha bater em uma parte do corpo da cobrinha" << endl;
        	cout << "Apos o jogo a pontuacao e armazenada e voce pode comparar a sua pontuacao com a de outros jogadores"<< endl;
        	cout << "Boa Sorte" << endl;
            cout<< "\n";
            system ("pause");
            system ("cls");
		}
        
        if (menu == 4)
        {
            exit(4);//sai do programa
        }
        
        // Continuacao do sistema de menu
        cout << "Menu de opcoes" << endl;
        cout << "Aperte 1 para jogar" << endl;
        cout << "Aperte 2 para ver o ranking" << endl;
        cout << "Aperte 3 para ver as instrucoes de como jogar" << endl;
        cout << "Aperte 4 para sair do jogo" << endl;
        cin >> menu;
        cout << "\n";

    }

    system ("pause");

    return 0;
}