#include <iostream>
#include <string>
using namespace std;

typedef struct Curso
{
	char nome[50];
	double preco;
} t_curso;

typedef struct Estudante
{
	char nome[50];
	Curso curso;
} t_estudante;

int main(int argc, char* argv[])
{
	t_estudante e;
	strcpy(e.nome, "Kelvin");
	strcpy(e.curso.nome, "C++ para Iniciantes");
	e.curso.preco = 10;

	cout << "Nome da pessoa: " << e.nome << endl;
	cout << "Curso: " << e.curso.nome << endl;
	cout << "Preco do curso: " << e.curso.preco << endl;

	return 0;
}