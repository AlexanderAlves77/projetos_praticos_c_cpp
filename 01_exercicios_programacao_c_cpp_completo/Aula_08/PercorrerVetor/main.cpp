#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	char nome[] = "Vamos estudar C++";

	for (int i = 0; nome[i]; i++)
		cout << nome[i];
	cout << endl;

	cout << nome << endl;
	return 0;
}