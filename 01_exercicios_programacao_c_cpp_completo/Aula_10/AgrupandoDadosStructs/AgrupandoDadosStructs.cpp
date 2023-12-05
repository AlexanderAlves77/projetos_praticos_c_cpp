#include <iostream>
using namespace std;

typedef struct pessoa
{
	char nome[100];
	int idade;
}t_pessoa;

int main(int argc, char* argv[])
{
	t_pessoa p[3];

	strcpy(p[0].nome, "Alexander");
	p[0].idade = 46;
	strcpy(p[1].nome, "Kelvin");
	p[1].idade = 22;
	strcpy(p[2].nome, "Sara");
	p[2].idade = 9;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Nome: " << p[i].nome << endl;
		cout << "Idade: " << p[i].idade << endl;
		cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n";
	}

	system("Pause");
	return 0;
}