#include <iostream>
#include <string.h>
using namespace std;

class Linguagem
{
	friend void classeAmiga(Linguagem*);
private:
	char nome[100];	
public:
	void mostrarNome()
	{
		cout << "Nome: " << nome << endl;
	}
	void setNome(const char* nome)
	{
		strcpy(this->nome, nome);
	}
};

class LinguagemAmiga
{
	friend class Linguagem;

protected:
	void mostrarAlgo()
	{
		cout << "Olá, linguagem amiga!\n";
	}
};

void classeAmiga(Linguagem* l)
{
	cout << "Classe amiga diz: " << l->nome << endl;
}

int main(int argc, char* argv[])
{
	Linguagem l;
	l.setNome("C++");
	l.mostrarNome();	

	return 0;
}