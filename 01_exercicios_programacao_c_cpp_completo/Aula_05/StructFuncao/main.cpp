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

int main(int argc, char * argv[])
{
	jogadir beto = {"Bebeto", 200000, 600};
	exibir(beto);	
	
	return 0;
}

void exibir(jogador j)
{
	cout << j.nome << " fez " << j.gols << " gols, recebendo R$ " << j.salario << endl;
}