#include <iostream>
using namespace std;

struct jogador
{
	char nome[20];
	float salario;
	unsigned gols;
};

void exibir(jogador vet[], int tam)
{
	for (int i = 0; i < tam; i++)
		cout << vet[i].nome << " " << vet[i].salario << " " << vet[i].gols << endl;
	cout << endl;
}

int main(int argc, char* argv[])
{	/*
	jogador time[2] = { {"Bebeto", 200000, 600}, {"Romario", 300000, 800} };
	int tamanho = sizeof(time) / sizeof(int);  */

	jogador* potiguar = new jogador[2];

	for (int i = 0; i < 2; i++)
		cin >> potiguar[i].nome >> potiguar[i].salario >> potiguar[i].gols;

	exibir(potiguar, 2);

	delete[] potiguar;

	return 0;
}