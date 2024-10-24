#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void kadane(vector<int>& vet)
{
	int max_atual = 0, max_total = -1;
	int size_vet = vet.size();

	for (int i = 0; i < size_vet; i++)
	{
		max_atual = max_atual + vet[i];

		if (max_atual < 0)
			max_atual = 0;
		if (max_atual > max_total)
			max_total = max_atual;
	}
	cout << "Soma maxima: " << max_total << endl;
}

int main(int argc, char* argv[])
{
	vector<int> vet(5);

	// vetor: -2, 5, -1, 2, -3
	vet[0] = -2;
	vet[1] = 5;
	vet[2] = -1;
	vet[3] = 2;
	vet[4] = -3;

	kadane(vet);

	return 0;
}
