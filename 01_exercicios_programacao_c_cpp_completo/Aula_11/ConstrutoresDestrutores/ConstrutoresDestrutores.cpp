#include <iostream>
//#include <string.h>
using namespace std;

class Pessoa
{
private:
	char nome[100];
	int idade;
	int* parentes;
public:
	Pessoa(const char* nome, int idade)
	{
		strcpy(this->nome, nome);
		this->idade = idade;
		parentes = new int[100];
		cout << "Entrou no construtor: " << nome << endl;
	}
	char* getNome()
	{
		return nome;
	}
	int getIdade()
	{
		return idade;
	}
	~Pessoa()
	{
		cout << "Entrou no destrutor..." << endl;
		delete[] parentes;
	}
};

int main(int argc, char* argv[])
{
	Pessoa pessoas[3] = { {"Alexander", 46}, {"Kelvin", 22}, {"Sara", 9} };

	for (int i = 0; i < 3; i++) {
		cout << "Nome: " << pessoas[i].getNome() << endl;
		cout << "Idade: " << pessoas[i].getIdade() << endl;
		cout << "**********************************\n";
	}	
	return 0;
}