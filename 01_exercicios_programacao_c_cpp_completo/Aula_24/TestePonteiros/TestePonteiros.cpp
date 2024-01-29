#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int var = 10;
	int *pvar = &var;
	string nome = "alexander";
	int tamanho = sizeof(nome) / sizeof(string);

	cout << "Variavel var: " << var << endl;
	cout << "Ponteiro pvar: " << pvar << endl;
	cout << "Referencia &var: " << &var << endl;
	cout << "Tamanho da variavel nome: " << tamanho << endl;

	system("Pause");
	return 0;
}