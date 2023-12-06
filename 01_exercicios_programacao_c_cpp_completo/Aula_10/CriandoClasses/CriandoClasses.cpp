#include <iostream>
using namespace std;

class Pessoa
{
private:
	
public:
	char nome[100];
	char cpf[20];
	int idade;
};

int getIdade(Pessoa pessoas[], const char* nome)
{
	int tam = sizeof(pessoas);

	for (int i = 0; i < tam; i++)
	{
		if (strcmp(nome, pessoas[i].nome) == 0)
			return pessoas[i].idade;
	}
	return -1;
}

int main(int argc, char* argv[])
{
	Pessoa pessoas[3] = {
		{ "Alexander", "1111111111111", 46 },
		{ "Kelvin", "1111111111111", 22 },
		{ "Sara", "1111111111111", 9 }
	};

	cout << "Nome: " << pessoas[0].nome << endl;
	cout << "Nome: " << pessoas[1].nome << endl;
	cout << "Nome: " << pessoas[2].nome << endl;

	int idade = getIdade(pessoas, "Kelvin");

	if (idade != -1)
		cout << "Idade do Kelvin: " << idade << endl;
	else
		cout << "Pessoa nao encontrada." << endl;

	return 0;
}