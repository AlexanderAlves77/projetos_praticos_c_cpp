#include <iostream>
using namespace std;

struct jogador
{
	char nome[40];
	float salario;
	unsigned gols;
};

void exibir_antigo(jogador j)
{
	cout << "Jogador: " << j.nome << endl;
	cout << "Salario: " << j.salario << endl;
	cout << "Gols: " << j.gols << endl;
}

void exibir(jogador* ptr)
{
	cout << "Jogador: " << ptr->nome << endl;
	cout << "Salario: " << ptr->salario << endl;
	cout << "Gols: " << ptr->gols << endl;
}

int main()
{
	jogador novato = { "Kelvin", 100000, 100 };
	exibir(&novato);
	cout << "===================================" << endl;
	exibir_antigo(novato);

	return 0;
}
