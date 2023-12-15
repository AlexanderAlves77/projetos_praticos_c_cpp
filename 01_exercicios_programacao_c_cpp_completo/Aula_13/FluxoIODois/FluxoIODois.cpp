#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream in("teste.txt");
	string texto;
	char c = in.get();
	texto.push_back(c);

	cout << "\nMostrando cada caracter:\n";
	while (in.good()) 
	{
		cout << c;
		c = in.get();
		texto.push_back(c);
	}
	cout << "\nMostrando a string:\n" << texto << endl;

	return 0;
}