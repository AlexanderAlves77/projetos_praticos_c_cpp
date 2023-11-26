#include <iostream>
using namespace std;

int main()
{
	double litros = 3.4;
	double* l = &litros;

	cout << litros << endl;
	cout << *l << endl;

	return 0;
}
