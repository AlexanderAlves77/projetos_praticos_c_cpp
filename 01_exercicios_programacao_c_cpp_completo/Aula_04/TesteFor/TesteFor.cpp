#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int num, fat = 1;
	cout << "Digite um numero: ";
	cin >> num;

	for (int i = 1; i < num; i++)
	{
		fat = fat * (i + 1);		
	}
	cout << "Fatorial de: " << num << " é: " << fat << endl;
	
	system("Pause");
	return 0;
}