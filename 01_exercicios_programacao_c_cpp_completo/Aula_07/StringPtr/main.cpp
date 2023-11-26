#include <iostream>
using namespace std;

int main()
{
	// inicializa vetor com a constante string
	char nome[20] = "Kelvizinho";
	cout << nome << endl;

	// guarda endereço do segundo caractere no ponteiro
	char* ptr = &nome[1];
	cout << ptr << endl;

	nome[0] = 'S';   // altera primeira posição do vetor
	*ptr = 'i';      // altera elemento apontado
	cout << nome << endl;

	return 0;
}