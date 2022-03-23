#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Jogador{//declaracao da classe jogador
	
	private:
		string nick;
		int pontos;
	
	public:
		Jogador(){//construtor
			nick = " ";
			pontos = 0;
		}
		
		void setNick(string n){
			nick = n;
		}
		
		void setPontos(int pontuacao){
			pontos = pontuacao;
		}
		
		string getNick(){
			return nick;
		}
		
		int getPontos(){
			return pontos;
		}

		void Cadastra(){
	
    		int pnts = 0;
			string name;
			fstream ranking;
    		
			ranking.open("ranking.txt", ios::app);//abre o arquivo que contem os nomes e pontuacoes dos jogadores

			cout << "Digite seu nickname: ";
			cin >> name;
			setNick(name);
			setPontos(pnts);

			ranking << getNick() << " " << getPontos() << endl;
	
			ranking.close();
		}

};