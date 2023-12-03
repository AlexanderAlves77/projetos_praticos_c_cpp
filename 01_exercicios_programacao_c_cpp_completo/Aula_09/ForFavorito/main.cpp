#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Digite um numero entre 0-10\n";

	for (cin >> n; n != 7; cin >> n)
		cout << "Errou, digite novamente: ";

	cout << "Sim, 7 e meu numero favorito.\n";

	return 0;
}