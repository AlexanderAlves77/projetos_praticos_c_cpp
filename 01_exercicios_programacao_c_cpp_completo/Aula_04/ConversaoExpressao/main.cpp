#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	char ch1 = '%';            // código ASCII % = 37
	char ch2 = '&';            // código ASCII % = 38
	short galinhas = 20;
	short patos = 35;

	// char´s para int e o resultado int para char
	char ch = ch1 + ch2;      // código ASCII K = 75

	// short´s para int e o resultado int para short
	short aves = galinhas + patos;

	char a = 90;
	char b = 70;
	int val = a + b;           // char é promovido para int

	float total = 2.50 * val;  // val é convertido para double

	// o valor 5 é convertido para double
	float total = 9.0 / 5;

	// o valor 5 é convertido para long long
	long long val2 = 163481190409292 + 5;

	// Erro - o resultado não cabe em um int
	long long erro = 100000000 * 2009;     // -963462912
	// certo
	long long certo = 100000000LL * 2009;  // 200900000000

	return 0;
}