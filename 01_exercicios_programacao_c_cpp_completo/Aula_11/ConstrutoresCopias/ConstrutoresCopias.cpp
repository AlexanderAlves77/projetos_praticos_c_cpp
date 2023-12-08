#include <iostream>
using namespace std;

class Estudante
{
protected:
	char* nome;
public:
	Estudante(const char* nome)
	{
		cout << "Contruindo objeto..." << endl;

		int tam = strlen(nome) + 1;
		this->nome = new char[tam];
		strcpy(this->nome, nome);
	}

	Estudante(const Estudante& e)
	{
		cout << "Contruindo copia..." << e.nome << endl;
		int tam = strlen(e.nome) + strlen("Copia de ") + 1;
		this->nome = new char[tam]; 
		strcpy(this->nome, "Copia de ");
		strcat(this->nome, e.nome);
	}

	~Estudante()
	{
		cout << "Destruindo..." << nome << endl;
		delete[] nome;
		nome = 0;
	}

	const char* getNome()
	{
		return nome;
	}
};

void foo2(Estudante e){}

void foo()
{
	Estudante estudante("kelvin");
	foo2(estudante);
	cout << "Estudante " << estudante.getNome() << endl;
}

int main(int argc, char* argv[])
{
	Estudante e("sara");

	return 0;
}
