#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int total = 6;
	int* ptr;

	ptr = &total;

	cout << "Conteudo do total = " << ptr << endl;
	cout << "Conteudo apontado = " << *ptr << endl;

	cout << "Endereco de total = " << &total << endl;
	cout << "Conteudo de ptr = " << ptr << endl;

	*ptr = *ptr + 1;
	cout << "Agora total vale = " << total << endl;

	return 0;
}