#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	// cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << fixed;

	float tres = 3;       // int convertido para float
	int aposta = 3.9832;  // double convertido para int  (foi truncado)
	int debito = 7.2E12;  // resultado não definido  (está errado)
	
	cout << "tres = " << tres << endl;
	cout << "aposta = " << aposta << endl;
	cout << "debito = " << debito << endl;
	
	return 0;
}