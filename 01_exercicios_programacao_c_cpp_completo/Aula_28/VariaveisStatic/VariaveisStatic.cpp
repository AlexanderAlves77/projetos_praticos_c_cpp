#include <iostream>
#include <string>
using namespace std;

int gerarID()
{
	static int ID = 1;
	return ID++;
}

int main(int argc, char* argv[])
{
	string nome;

	while (true)
	{
		cout << "Digite o nome da pessoa: ";
		cin >> nome;
		cout << "ID gerado para o usuario " << nome << ": " << gerarID() << "\n\n";
	}
	return 0;
}
