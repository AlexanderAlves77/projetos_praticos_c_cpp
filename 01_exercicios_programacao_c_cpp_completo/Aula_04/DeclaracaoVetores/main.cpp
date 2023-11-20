#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	constexpr int Tam = 5 * sizeof(int);
	const int Max = rand();
	
	cout << "Tam: " << Tam << endl;
	cout << "Max: " << Max << endl;
	
	int val[Tam];
	int val[Max];                    // erro - Max não é uma expressão constante
	
	return 0;
}