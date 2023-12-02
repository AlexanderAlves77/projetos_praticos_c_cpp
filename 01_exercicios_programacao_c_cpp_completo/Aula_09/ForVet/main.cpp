#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int vet[5] = { 3, 5, 6, 7, 9 };

	for (int n : vet)
		cout << n << " ";
	cout << endl;

	return 0;
}