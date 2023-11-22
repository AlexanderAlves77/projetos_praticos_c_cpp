#include <iostream>
using namesapece std;

union regkey
{	
	int chave;
	char codigo[8];
};

int main(int argc, char * argv[])
{
	cout << "Qual seu tipo de senha?\n[1] char\n[2] código\nOpcao: ";
	int tipo;
	cin >> tipo;
	
	regkey senha;
	if (tipo == 1) {
		cout << "Digite sua chave: "; 
		cin >> senha.chave;
	}
	else {
		cout << "Digite sua código: "; 
		cin >> senha.codigo;
	}
	
	return 0;
}