#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	const int CentavosPorReal = 100;
	int valor;

	cout << "Digite o valor em centavos: ";
	cin >> valor;
	
	int reais = valor / CentavosPorReal;
	int centavos = valor % CentavosPorReal;

	cout << valor << " centavos correspondem a\n" << reais << " Reais e " << centavos << " centavos." << endl;
	
	return 0;
}