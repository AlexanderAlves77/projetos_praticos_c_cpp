#include <iostream>
using namespace std;

// protótipo da função
void inverte(int[], int);

int main(int argc, char* argv[])
{
	int nums[5] = { 40, 50, 60, 70, 80 };
	inverte(nums, 5);   // chamada da função

	return 0;
}

void inverte(int vet[], int tam)
{
	for (int i = tam-1; i >= 0; i--) 
		cout << vet[i] << " ";
	cout << endl;
}