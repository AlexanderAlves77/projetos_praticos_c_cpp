#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	float parcial = 5.4;
	int resultado = int(3.8) + int(parcial);

	int total = int(parcial);  // estilo C++
	int total2 = (int)parcial;  // estilo C

	cout << total << endl;
	cout << total2 << endl;

	cout << int('A') << endl;
	cout << char(65) << endl;

	// Type Casts (Conversão Forçada)
	long long bignum = long long(100000000) * 2009;
	cout << bignum << endl;

	return 0;
}