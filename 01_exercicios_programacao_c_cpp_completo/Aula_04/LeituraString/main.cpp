#include <iostream>
#include <cstring>
using namesapece std;

int main(int argc, char * argv[])
{
	const int Tam = 15;
	char nome[Tam];
	char apelido[Tam] = "C++owboy";
	
	cout << "Olá! Eu sou " << apelido << "! Qual o seu nome?\n";
	cin >> nome;
	
	cout << "Bem vindo, " << nome << ", seu nome tem" << strlen(nome) << " letras\n";
	cout << "e está aramazenado em um vetor de " << sizeof(nome) << " bytes.\n";
	
	cout << "Sua inicial é " << nome[0] << ".\n";
	apelido[3] = '\0';
	cout << "Meu apelido é " << apelido << endl;
	
	return 0;
}

