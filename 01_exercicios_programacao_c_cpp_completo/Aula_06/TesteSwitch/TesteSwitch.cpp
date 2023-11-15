#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int num1, num2, resultado;
	float div;
	char operacao;

	cout << "Digite o primeiro numero: ";
	cin >> num1;
	cout << "Digite o segundo numero: ";
	cin >> num2;
	cout << "Digite a operacao:  ";
	cin >> operacao;

	switch(operacao)
	{
	case '+':
		resultado = num1 + num2;
		cout << "Soma: " << resultado << endl;
		break;
	case '-':
		resultado = num1 - num2;
		cout << "Subtracao: " << resultado << endl;
		break;
	case '*':
		resultado = num1 * num2;
		cout << "Multiplicacao: " << resultado << endl;
		break;
	case '/':
		if (num2 != 0)
		{
			div = num1 / num2;
			cout << "Divisao: " << div << endl;
		}
		else
		{
			cout << "Divisao por zero!" << endl;
		}
		
		break;
	default:
		cout << "Operacao inexistente." << endl;
		break;
	}
	
	system("Pause");
	return 0;
}