#include <iostream>
#include <cmath>
using namespace std;

bool fltcmp(float a, float b)
{
	const float erro = 0.001;
	if (abs(a - b) < erro) return true;
	else return false;
}

int main()
{
	float a = 6.9f;
	float b = 0.9f;

	// Valores ponto flutuantes não devem ser comparados usando o operador relacional de igualdade
	cout << boolalpha << (a - int(a) == b) << endl;

	return 0;
}