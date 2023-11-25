#include <iostream>
using namespace std;

enum mes { Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez };

istream& operator>>(istream& is, mes& m)
{
	int temp;
	is >> temp;
	m = (mes)temp;
	return is;
}

int main()
{
	mes inicio, fim; // cria vari�veis do tipo m�s

	inicio = Fev;   // inicio do semestre
	fim = Nov;		// fim do semestre

	cout << "Digite o numero do mes atual: ";
	mes atual;
	cin >> atual;    // l� o m�s atual para uma vari�vel inteira

	if (atual >= inicio && atual <= fim)
		cout << "Voce esta em periodo de aulas.\n";
	else
		cout << "Ferias!\n";

	return 0;
}