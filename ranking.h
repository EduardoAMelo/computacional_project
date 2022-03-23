//bibliotecas
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;


void Rank(){
	
	Jogador usuario[100];
	Jogador jogadores[100];
	list <int> pontuacoes;//lista auxiliar criada
	fstream ranking;//arquivo que vai ser manipulado
	int quant_jogadores=0;
	int transf,pos=0;//inteiros auxiliares
	char c[100];//precisa disso pra transformar a string em inteiro, porque vi o video na internet tentei sem e nao da certo
	string caractere;
	string aux_str;
	string s;
	string aux_num;
	
	ranking.open("ranking.txt",ios::trunc);//tem que abrir primeiramente para leitura
	
	while(getline(ranking,s)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		aux_num = ' ';
		aux_str = ' ';
		for(unsigned int i = 0; i <= s.size(); i++){
			if(caractere[i] == '\n'){//quando o caractere for igual a quebra de linha quer dizer que um jogador foi cadastrado no arquivo
				quant_jogadores += 1;
			}
			if(caractere[i] != ' ' and not'1' and not'2' and not '3' and not'4' and not'5' and not'6' and not'7' and not'8' and not'9'){
				aux_str = aux_str + caractere[i];//Se o carctere na posicao i for uma letra vai copiar e vai acumular ate for diferente de espaco onde acaba o nome e tambem quando for diferente de algum numero pra nao acumular numeros
			}
			if(caractere[i] == '0' or '1' or '2' or '3' or '5' or '6' or '7' or '8' or '9'){
				aux_num = aux_num + caractere[i];//Se o carctere na posicao i for numerico ele copia pra uma string aux_num e vai acumulando
			}
		}
		transf = atoi(aux_num.c_str());//transforma a string numerica em int
		pontuacoes.push_back(transf);//coloca o int em uma nova lista
		usuario[pos].setNick(aux_str);//armazena os nomes que foram lidos no arquivo txt em um objeto da classe jogador
		usuario[pos].setPontos(transf);//armazena as pontuacoes que foram lidas no arquivo txt em um objeto da classe jogador
		pos++;
	}

	pontuacoes.sort();//ordenacao de pontos
	pontuacoes.reverse();//coloca em ordem decrescente 
	
	for(int j = 0; j < quant_jogadores; j++){
		for(int p = 0; p < quant_jogadores; p++){
			if(pontuacoes.front() == usuario[p].getPontos()){//compara a pontuacao dos jogadores com as pontuacoes da lista
				jogadores[j].setNick(usuario[p].getNick());//ainda tem um erro que eu estava pensado se tiverem dois jogadores com a mesma pontuacao vai tirar um jogador que esta na lista
				jogadores[j].setPontos(usuario[p].getPontos());//vou pensar em como resolver o problema de cima
				break;//com o break ele para a comparacao 
			}
		}
		pontuacoes.pop_front();//precisa tirar o maior valor apos a comparacao pra poder comparar as pontuacoes dos jogadores com o proximo valor de pontuacao 
	}
	
	//reescreve o ranking no arquivo txt
	for(int n = 0; n < quant_jogadores; n++){
		ranking << jogadores[n].getNick() << " " << jogadores[n].getPontos() << "\n";//imprime no arquivo .txt os usuarios e suas pontuacoes ja ordenadas
	}

	//imprime o ranking no terminal
	cout << "Ranking: " << endl;
	cout << "  Nome         Pontos" << endl;
	for(int m = 0,posicao = 1; m < quant_jogadores; m++, posicao++){
		cout << posicao << " " << jogadores[m].getNick() << "     " << jogadores[m].getPontos() << "\n";
	}
		
    if (quant_jogadores == 100)//quando a quantidade de jogaores dentro do arquivo txt chegar a 100 vai recomecar
    {
		ranking.clear();//apaga o conteudo do arquivo txt
        quant_jogadores = 0;
    }
    

	ranking.close();//fecha o arquivo
}