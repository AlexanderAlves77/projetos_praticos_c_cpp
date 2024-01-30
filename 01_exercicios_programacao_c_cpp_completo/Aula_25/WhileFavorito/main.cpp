#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Digite um numero entre 0-10\n";

	cin >> n;
	while (n != 7)
	{
		cout << "Errou, digite outro: ";
		cin >> n;
	}

	cout << "Sim, 7 e meu numero favorito.\n";

	return 0;
}