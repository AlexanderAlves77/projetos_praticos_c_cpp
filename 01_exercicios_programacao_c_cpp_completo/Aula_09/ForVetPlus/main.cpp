#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int vet[5] = { 3, 5, 6, 7, 9 };

	for (char ch = 'a'; int n : vet)
		cout << ch++ << ": " << n << "\n";
	cout << endl;

	return 0;
}