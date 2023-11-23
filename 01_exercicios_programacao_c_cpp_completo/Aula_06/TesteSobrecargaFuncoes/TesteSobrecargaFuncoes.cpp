#include <iostream>
using namespace std;

void mensagem(int n)
{
	cout << "numero: " << n << endl;
}

void mensagem()
{
	cout << "Hello World " << endl;
}

int main(int argc, char* argv[])
{
	mensagem(10);
	mensagem();
	system("Pause");
	return 0;
}