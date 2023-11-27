#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int vetor[100];
	
	for (int i = 0; i < 100; i++)
		vetor[i] = i;
	for (int i = 0; i < 100; i++)
		cout << "Indice: " << vetor[i] << endl;

	system("Pause");
	return 0;
}