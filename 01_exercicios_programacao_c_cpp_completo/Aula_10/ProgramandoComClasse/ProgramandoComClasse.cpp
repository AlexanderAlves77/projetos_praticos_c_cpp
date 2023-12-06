#include <iostream>

using namespace std;

class Conta
{
public:
	int numero;
	double saldo;

	double depositar(double quantidade);
	double depositar(int quantidade);

	double retirar(double quantidade)
	{
		if (quantidade > 0 && saldo >= quantidade)
			saldo -= quantidade;
		return saldo;
	}
};

double Conta::depositar(double quantidade)
{
	if (quantidade > 0)
		this->saldo += quantidade;
	return this->saldo;
}
double Conta::depositar(int quantidade)
{
	if (quantidade > 0)
		this->saldo += quantidade;
	return this->saldo;
}

int main(int argc, char* argv[])
{
	Conta c;
	Conta* pc = &c;

	pc->numero = 1;
	pc->saldo = 200;

	cout << "Saldo: " << c.saldo << endl;
	cout << "Saldo depois do deposito: " << c.depositar(100) << endl;
	cout << "Saldo depois do saque: " << c.retirar(50) << endl;

	return 0;
}