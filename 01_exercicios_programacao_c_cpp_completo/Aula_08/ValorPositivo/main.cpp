#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int x;
	
	cout << "Digite um valor positivo: ";
	for (cin >> x; x < 0; cin >> x)    
		cout << "Digite um valor positivo: ";

	cout << 2 * x << endl;
	return 0;
}