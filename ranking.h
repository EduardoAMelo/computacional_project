//bibliotecas
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#define TAM_HASH 199

using namespace std;


void Rank(){
	
	Jogador usuario[100];
	Jogador jogadores[100];
	list <int> pontuacoes;//lista auxiliar criada
	fstream ranking;//arquivo que vai ser manipulado
	int quant_jogadores=0;
	char escolha;
	int transf,pos=0;//inteiros auxiliares
	char c[100];//precisa disso pra transformar a string em inteiro
	string aux_str;
	string s;
	string aux_num;
	string acesso[TAM_HASH];
	int hash[100];
	int posicao;
	
	ranking.open("ranking.txt",ios::in);//tem que abrir primeiramente para leitura
	
	while(getline(ranking,s)){//while com o getline e usado para passar de linha a linha no arquivo de leitura
		aux_num = ' ';//usado para recomecar a acumulacao de carcteres numericos
		aux_str = ' ';//usado para recomecar a acumulacao de carcteres de letras
		hash[quant_jogadores] = 0;
		for(unsigned int i = 0; i <= s.size(); i++){
			if(s[i] == '.'){//quando o caractere for igual ao ponto quer dizer que um jogador foi cadastrado no arquivo
				quant_jogadores += 1;
			}
			if((s[i] != ' ') && (s[i] != '.') && (s[i] != '0') && (s[i] != '1') && (s[i] != '2') && (s[i] !='3') && (s[i] !='4') && (s[i] !='5') && (s[i] !='6') && (s[i] !='7') && (s[i] !='8') && (s[i] !='9')){
				aux_str = aux_str + s[i];//Se o carctere da linha lida na posicao i for uma letra vai copiar e vai acumular ate for diferente de espaco onde acaba o nome e tambem quando for diferente de algum numero pra nao acumular numeros
				hash[quant_jogadores] += s[i];//primeira parte do calculo de hash do nome, pega caractere por caractere e faz o somatorio por meio do codigo ASCII
			}
			if((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] =='3') || (s[i] =='4') || (s[i] =='5') || (s[i] =='6') || (s[i] =='7') || (s[i] =='8') || (s[i] =='9')){
				aux_num = aux_num + s[i];//Se o carctere na posicao i for numerico ele copia pra uma string aux_num e vai acumulando
			}
		}
		posicao = hash[pos] % TAM_HASH;//cria a posicao de acesso que o nome de cada usuario vai ter(vou chamar de funcao hash)
		transf = atoi(aux_num.c_str());//transforma a string numerica em int
		pontuacoes.push_back(transf);//coloca o int em uma nova lista
		usuario[pos].setNick(aux_str);//armazena os nomes que foram lidos no arquivo txt em um objeto da classe jogador
		usuario[pos].setPontos(transf);//armazena as pontuacoes que foram lidas no arquivo txt em um objeto da classe jogador
		if (acesso[posicao].size() != 0)//caso a posicao criadada pela funcao hash esteja ocupada ,ou seja, o tamanho do nome diferente de 0, ele entrara no if
		{
			while (acesso[posicao].size() != 0)//enquanto a posicao nao esteja vazia ele repetira o loop while ate encontar uma posicao vazia e depositara o nome para nao ocorrer colisoes
			{
				if (posicao == 198)//se a posicao 198 estiver ocupada o array precisa voltar para a posicao 0 de acordo com a teoria de tabelas hash
				{
					posicao = 0;
					if (acesso[posicao].size() == 0)//verificacao pra saber se na posicao 0 ja existe algum nick do usuario
					{
						break;//se o tamanho do nome da posicao 0 for igual a 0, quer dizer que nao tem nenhuma string nessa posicao e interrompe o loop while para o nome ser armazenado na posicao 0
					}
					
				}
				posicao += 1;//a posicao aumenta um porque na tabela hash quando uma posicao e ocupada ele passa para a posicao seguinte
				
			}
			acesso[posicao] = usuario[pos].getNick();//concede uma posicao na tabela hash para o nome que acabou de ser lido
		}
		else{//caso a posicao esteja vazia ele nao entra no if acima e ja e armazenado na posicao que a funcao hash gerou
			acesso[posicao] = usuario[pos].getNick();//concede uma posicao na tabela hash para o nome que acabou de ser lido
		}
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
				usuario[p].setPontos(0);//apaga a pontuacao do usuario[p] porque se dois jogadores tiverem a mesma pontuacao o programa pode colocar os dois no ranking
				break;//com o break ele para a comparacao 
			}
		}
		pontuacoes.pop_front();//precisa tirar o maior valor apos a comparacao pra poder comparar as pontuacoes dos jogadores com o proximo valor de pontuacao 
	}
	
	ranking.open("ranking.txt",ios::out|ios::trunc);//abre pra sobreescrita
	//reescreve o ranking no arquivo txt
	for(int n = 0; n < quant_jogadores; n++){
		ranking <<jogadores[n].getNick() << " " <<jogadores[n].getPontos() << "." << "\n";//imprime no arquivo .txt os usuarios e suas pontuacoes ja ordenadas
	}

	//atribui a cada jogador uma posicao
	for(int n = 0; n < quant_jogadores; n++){
		jogadores[n].setPosicao(n + 1);
	}

	//imprime o ranking no terminal
	cout << "Ranking: " << endl;
	cout << "  Nome" << setw(30) << left << "Pontos" << endl;
	for(int m = 0; m < quant_jogadores; m++){
		cout << setw(4) << left << jogadores[m].getPosicao() << setw(30) << left << jogadores[m].getNick() << " \7\t " << jogadores[m].getPontos() << "\n";
	}
	cout << endl;
	
	//menu hash
	cout << "Aperte 'h' para procurar algum jogador no ranking, ou aperte 'v' para voltar ao menu principal \n";
	cin >> escolha;

	while( escolha != 'v'){

		if (escolha == 'v')
		{
			exit;
		}

		if (escolha == 'h')
		{
			string chave;
			int th=0;
			int contador=0;
			
			cout << "Que nome deseja procurar ? Digite o nome sem espacos, sem numeros e sem ponto final: ";
			cin >> chave;//o usuario coloca o nome que desja procurar na tabela hash

			//primeira parte do calculo de hash, soma os caracteres um por um de acordo com os valores da tabela ascii
			for(int a=0; a <= chave.size(); a++){
				th += chave[a];
			}

			posicao = th % TAM_HASH;//calcula qual sera a posicao para o nome que foi pesquisado
			cout << posicao << endl;//teste
			if (acesso[posicao].size() == 0)//caso nao tenha nada na posicao pesqisada quer dizer que o nome nao pode ser encontrado
			{
				cout << "Jogador nao encontrado " << endl;
				cout << "\n";
			}
			else{//caso tenha algo escrito entrara no loop while
				while (acesso[posicao].size() != 0)//e importante a verificacao para saber se existe algum nome na posicao
				{
					cout << acesso[posicao] << endl; //teste 
					//a comparacao abaixo ainda nao funciona mesmo se eu digitar um nome que eu sei que esta no ranking
					if (chave == acesso[posicao])//se o nome digitado pelo usuario for igual ao nome da posicao em acesso ele entra na condicao if
					{
						cout << "informacoes do jogador: " << endl;
						cout << " Nomes \t Pontos" << endl;
						for(int b = 0; b < quant_jogadores; b++){//como podem ter jogadores com o mesmo nome entao precisamos percorrer tudo para caso exista  nos conseguimos imprimir as informacoes dos jogadores com o mesmo nick e com nicks que nao se repetem
							if (chave == jogadores[b].getNick())//caso a chave digitda seja igual ao nome do jogador na posicao b ele imprime as informacoes desse jogador
							{
								cout << jogadores[b].getPosicao() << " " << jogadores[b].getNick() << "\t" << jogadores[b].getPontos() << "\n";							
							}
						}
						contador++;//temos que ter um contador porque pode ser que o nome pesquisado, ou seja a chave, tenha o mesmo valor de hash que outro nome mesmo sendo diferentes, e nos nao queremos o nome de uma certa posicao, mas queremos um nome especifico que pode nem estar na tabela,porem tendo o mesmo hash de um nome que esta 
					}
					posicao++;//a posicao aumenta para pordermos verificar os nomes que estao na posicao seguinte
				}
			}
			if(contador == 0){//caso o nome procurado nao esteja na tabela mesmo tendo hash igual a de outro ele nao acrescentara no contador entao o nome nao esta na tabela, por isso imprimimos a seguinte mensagem
				cout << "Nome nao encontrado na tabela hash" << endl;
			}
	
		}
		cout << "Aperte 'h' para procurar algum jogador no ranking, ou aperte 'v' para voltar ao menu principal \n";
		cin >> escolha;
	}
	// Impressao dos nomes nas posicoes da tabela hash
	for(int p = 0; p < TAM_HASH; p++){
		cout << p <<" " << acesso[p] << endl;
	}
	

	ranking.close();//fecha o arquivo

}