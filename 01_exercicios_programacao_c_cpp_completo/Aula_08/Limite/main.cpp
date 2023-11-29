#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Digite o valor do contador: ";
	int limite;
	cin >> limite;

	int i;   
	for (i = limite; i ; i--)    // encerra quando i é 0
		cout << "i = " << i << endl;

	cout << "Finalizando agora que i = " << i << endl;

	return 0;
}