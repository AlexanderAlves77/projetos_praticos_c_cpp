#include <iostream>
using namespace std;

class Animal
{
protected:
	char* nome;

public:
	Animal(const char* nome)
	{
		cout << "Construindo animal..." << endl;
		this->nome = new char[strlen(nome) + 1];
		strcpy(this->nome, nome);
	}
	~Animal()
	{
		delete[] nome;
		nome = 0;
	}
	const char* getNome()
	{
		return nome;
	}
};

class Cachorro : public Animal
{
protected:
	int idade;

public:
	Cachorro(const char* nome) : Animal(nome)
	{
		cout << "Construindo cachorro..." << endl;
		idade = 0;
	}
	int getIdade()
	{
		return idade;
	}
	void setIdade(int idade)
	{
		this->idade = idade;
	}
};

int main(int argc, char* argv[])
{
	Cachorro c("yankee");
	c.setIdade(5);

	cout << "Nome: " << c.getNome() << endl;
	cout << "Idade: " << c.getIdade();
	return 0;
}