/*

teste de cadastro

*/
#include <iostream>
#include <string>
#include <list>

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
};

void Cadastra(){
	
	list<Jogador>player;//criacao da lista 
	Jogador usuario[100];
    int i,pnts;
	string name;
    Jogador usuario_aux;
	
    i = quant_jogadores;

	cout << "Digite seu nickname: ";
	cin >> name;
	usuario[i].setNick(name);
	usuario[i].setPontos(pnts);
	player.push_front(usuario[i]);
	
	cout << "Nome do jogador: " << usuario[i].getNick() << endl;
	cout << "Pontuacao do jogador " << usuario[i].getNick() << " " << usuario[i].getPontos();

    
	
}