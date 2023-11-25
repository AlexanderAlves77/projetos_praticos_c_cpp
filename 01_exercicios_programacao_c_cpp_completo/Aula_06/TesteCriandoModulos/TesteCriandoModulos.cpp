#include <iostream>
#include "Modulo.h"
using namespace std;

int main(int argc, char* argv[])
{
	int n = 5;
	int b = 7;
	cout << "Fatorial de " << n << ": " << fatorial(n) << endl;
	cout << "Area do quadrado de " << n << ": " << area_quadrado(n) << endl;
	cout << "Area do retangulo de " << n << "*" << b << ": " << area_retangulo(n, b) << endl;
		
	system("Pause");
	return 0;
}