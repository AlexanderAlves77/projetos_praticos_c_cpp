#include <iostream>
#include <string>
using namespace std;

typedef struct Pessoa
{
	string nome;
	int idade;
	double peso, altura;
} t_pessoa;

int potencia(double x)
{
	return x * x;
}

double& calcular_imc(t_pessoa& pessoa)
{
	double result = pessoa.peso / (pessoa.altura * pessoa.altura);
	double& imc = result;
	return imc;
}


int main(int argc, char* argv[])
{
	t_pessoa pessoa = { "Kelvin", 22, 85.47, 1.75 };
	cout << "IMC: " << calcular_imc(pessoa) << endl;

	return 0;
}
