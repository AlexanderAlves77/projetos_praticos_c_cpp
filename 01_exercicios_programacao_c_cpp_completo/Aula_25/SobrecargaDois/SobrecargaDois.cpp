#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
private:
	char* nome;
	int id;
public:
	Pessoa(const char* novoNome, int novoID)
	{
		int tam = strlen(novoNome) + 1;
		nome = new char[tam];
		strcpy(nome, novoNome);
		id = novoID;
	}
	~Pessoa()
	{
		delete[] nome;
		nome = 0;
	}
	const char* getNome()
	{
		return nome;
	}
	int getID()
	{
		return id;
	}

	void mudarNome(char l)
	{
		nome[0] = l;
	}
};

int main(int argc, char* argv[])
{
	Pessoa p1("Alexander", 1), p2("Kelvin", 2);
	p1 = p2;
	p1.mudarNome('A');

	cout << "Nome: " << p1.getNome() << endl << "ID:" << p1.getID() << endl;
	cout << "Nome: " << p2.getNome() << endl << "ID:" << p2.getID() << endl;
	return 0;
}
