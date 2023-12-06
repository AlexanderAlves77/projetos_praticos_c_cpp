#include <iostream>
using namespace std;

void exibir();

int main()
{
	for (int i = 0; i < 5; ++i)
		exibir();
}

void exibir()
{
	// variável estática, a inicialização acontece apenas uma vez
	static int cont = 1;
	cout << cont++ << endl;
}
