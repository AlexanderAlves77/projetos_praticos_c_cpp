#include <iostream>
using namespace std;

int somaVetor(int []);

int main(int argc, char * argv[])
{
	int batatas[3] = {7, 8, 6};  // cria vetore de 3 elementos
	cout << "Total de batatas = ";
	cout << somaVetor(batatas) << endl;
	
	system("Pause");
	return 0;
}

int somaVetor(int []) 
{
	return vet[0] + vet[1] + vet[2];
}