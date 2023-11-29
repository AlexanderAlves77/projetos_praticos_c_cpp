#include <iostream>
using namespace std;

void antigo(int vet[])
{
	cout << vet[0] << " " << vet[1] << " " << vet[2] << " " << vet[3] << " " << vet[4] << endl;
}

void exibir(int vet[], int tam)
{
	for (int i = 0; i < tam; i++)
		cout << vet[i] << " ";
	cout << endl;
}

int main(int argc, char* argv[])
{
	int nums[] = { 30, 40, 50, 60, 70, 80, 90 };
	int tamanho = sizeof(nums) / sizeof(int);
	//antigo(nums);
	exibir(nums, tamanho);

	return 0;
}