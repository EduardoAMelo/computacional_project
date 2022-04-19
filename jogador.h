#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Jogador{//declaracao da classe jogador
	
	private://atributos privados
		string nick;
		int pontos;
		int posicao;
	
	public:
		Jogador(){//construtor
			nick = "unknow";
			pontos = 1;
			posicao = 0;
		}
		
		//metodos setters e getters
		void setNick(string n){
			nick = n;
		}
		
		void setPontos(int pontuacao){
			pontos = pontuacao;
		}

		void setPosicao(int p){
			posicao = p;
		}
		
		string getNick(){
			return nick;
		}
		
		int getPontos(){
			return pontos;
		}

		int getPosicao(){
			return posicao;
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