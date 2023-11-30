#include <iostream>
#include <string.h>
using namespace std;

void inverte(char nome[])
{
	int tam;
	for (tam = 0; nome[tam]; tam++);
	for (int i = tam - 1; i >= 0; i--)
		cout << nome[i];
}

int main(int argc, char* argv[])
{
	//char nome[] = { 'a', 'l', 'e', 'x', 'a', 'n', 'd', 'e', 'r', '\0' };
	char nome[] = "alexander";
	int i = 0;
	//cout << sizeof(nome) << endl;

	/*
	do
	{
		cout << nome[i];
	} while(nome[i++]);
		
	while (nome[i] != '\0')
		cout << nome[i++] << endl;
	*/
	inverte(nome);
	cout << endl;
	
	system("Pause");
	return 0;
}