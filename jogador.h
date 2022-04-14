#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Jogador{//declaracao da classe jogador
	
	private://atributos privados
		string nick;
		int pontos;
	
	public:
		Jogador(){//construtor
			nick = "unknow";
			pontos = 1;
		}
		
		//metodos setters e getters
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

		//metodo de cadastro 
		void Cadastra(){
	
    		int pnts = 0;
			string name;
	
			cout << "Digite seu nickname: ";
			cin >> name;
			setNick(name);
			setPontos(pnts);
	
		}

};