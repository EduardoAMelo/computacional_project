#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "jogador.h"

using namespace std;

void Rank(){
	
	fstream ranking;
	int quant_jogadores=0;
	char caractere;
	string s;
	
	ranking.open("ranking.txt",ios::trunc);
	
	while(getline(ranking,s)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		for(unsigned int i=0; i<=s.size(); i++){
			if(caractere == '\n'){
				quant_jogadores += 1;
			}
		}
	}
	
	ranking << "Quantidade de jogadores: " << quant_jogadores;
	
	/*
	player.sort();
	for(it_p = it_p.begin; it_p != it_p.end(); it_p++){
		ranking << *it_p << endl;
	}
	*/

    //ordenacao de usuarios
	for(int k=0; k < player.size; k++){
		for(int j=0; j < k; j++){
			if(usuario[k].getPontos() > usuario[j].getPontos){
				aux_usuario = usuario[j];
				usuario[j] = usuario[k];
				usuario[k] = aux_usuario;
			}
		}
	}
	
	for(int n=0; n < player.size; n++){
		ranking << usuario[n].getNick() << "     " << usuario[n].getPontos << "\n";//imprime no arquivo .txt os usuarios e suas pontuacoes ja ordenadas
	}
		
    if (player.size() == 100)
    {
        player.clear();
        quant_jogadores = 0;
    }
    

	ranking.close();
}