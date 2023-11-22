#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namesapece std;

struct jogador
{
	char nome[40];
	float salario;
	unsigned gols;
};

void exibir(jogador);
jogador ler();

int main(int argc, char * argv[])
{
	cout << "Digite as informacoes sobre o jogador:\n";
	jogadir beto = ler();
	exibir(beto);	
	
	return 0;
}

void exibir(jogador j)
{
	cout << j.nome << " fez " << j.gols << " gols, recebendo R$ " << j.salario << endl;
}

jogador ler()
{
	jogador temp;
	cin >> temp.nome;
	cin >> temp.salario;
	cin >> temp.gols;
	return temp;
}