// definindo e usando uma referência
#include <iostream>
using namespace std;

int main()
{
	int ratos = 101;
	int& roedores = ratos;  // roedores é uma referência
	int* pragas = &ratos;

	cout << "ratos = " << ratos;
	cout << ", roedores = " << roedores << endl;

	roedores++;

	cout << "ratos = " << ratos;
	cout << ", roedores = " << roedores;
	cout << ", pragas = " << *pragas << endl;

	cout << "endereco de ratos    = " << &ratos << endl;
	cout << "endereco de roedores = " << &roedores << endl;
	cout << "ebdereco de pragas   = " << pragas << endl;

	return 0;
}