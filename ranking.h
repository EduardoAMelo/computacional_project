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
	char c[100];//precisa disso pra transformar a string em inteiro
	string carac;
	string aux_str;
	string s;
	string aux_num;
	
	ranking.open("ranking.txt",ios::in);//tem que abrir primeiramente para leitura
	
	while(getline(ranking,s)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		aux_num = ' ';
		aux_str = ' ';
		for(unsigned int i = 0; i <= s.size(); i++){
			if(s[i] == '.'){//quando o caractere for igual ao ponto quer dizer que um jogador foi cadastrado no arquivo
				quant_jogadores += 1;
			}
			if((s[i] != ' ') && (s[i] != '.') && (s[i] != '0') && (s[i] != '1') && (s[i] != '2') && (s[i] !='3') && (s[i] !='4') && (s[i] !='5') && (s[i] !='6') && (s[i] !='7') && (s[i] !='8') && (s[i] !='9')){
				aux_str = aux_str + s[i];//Se o carctere da linha lida na posicao i for uma letra vai copiar e vai acumular ate for diferente de espaco onde acaba o nome e tambem quando for diferente de algum numero pra nao acumular numeros
			}
			if((s[i] == '0') or (s[i] == '1') or (s[i] == '2') or (s[i] =='3') or (s[i] =='4') or (s[i] =='5') or (s[i] =='6') or (s[i] =='7') or (s[i] =='8') or (s[i] =='9')){
				aux_num = aux_num + s[i];//Se o carctere na posicao i for numerico ele copia pra uma string aux_num e vai acumulando
			}
		}
		transf = atoi(aux_num.c_str());//transforma a string numerica em int
		pontuacoes.push_back(transf);//coloca o int em uma nova lista
		usuario[pos].setNick(aux_str);//armazena os nomes que foram lidos no arquivo txt em um objeto da classe jogador
		usuario[pos].setPontos(transf);//armazena as pontuacoes que foram lidas no arquivo txt em um objeto da classe jogador
		pos++;
	}
	ranking.close();

	pontuacoes.sort();//ordenacao de pontos
	pontuacoes.reverse();//coloca em ordem decrescente 
	
	//ordenacao dos nicks de acordo com as pontuacoes
	for(int j = 0; j < quant_jogadores; j++){
		for(int p = 0; p < quant_jogadores; p++){
			if(pontuacoes.front() == usuario[p].getPontos()){//compara a pontuacao dos jogadores com as pontuacoes da lista
				jogadores[j].setNick(usuario[p].getNick());//quando dois jogadores tem a mesma nenhum aparece duas vezes no ranking, apenas se o usuario usar o mesmo nick toda vez que jogar
				jogadores[j].setPontos(usuario[p].getPontos());
				usuario[p].setNick("NULL");//apaga o usuario[p] porque se dois jogadores tiverem a mesma pontuacao o programa pode colocar os dois no ranking
				usuario[p].setPontos(0);
				break;//com o break ele para a comparacao 
			}
		}
		pontuacoes.pop_front();//precisa tirar o maior valor apos a comparacao pra poder comparar as pontuacoes dos jogadores com o proximo valor de pontuacao 
	}
	
	ranking.open("ranking.txt",ios::out|ios::trunc);//abre pra sobreescrita
	//reescreve o ranking no arquivo txt
	for(int n = 0; n < quant_jogadores; n++){
		ranking << jogadores[n].getNick() << " " << jogadores[n].getPontos() << "." << "\n";//imprime no arquivo .txt os usuarios e suas pontuacoes ja ordenadas
	}

	//imprime o ranking no terminal
	cout << "Ranking: " << endl;
	cout << "  Nome\t Pontos" << endl;
	for(int m = 0,posicao = 1; m < quant_jogadores; m++, posicao++){
		cout << posicao << " " << jogadores[m].getNick() << "\t" << jogadores[m].getPontos() << "\n";
	}

	ranking.close();//fecha o arquivo

}