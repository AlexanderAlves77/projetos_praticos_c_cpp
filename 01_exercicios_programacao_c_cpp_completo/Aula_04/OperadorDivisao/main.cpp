#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << fixed;

	cout << "Divisao Inteira: 9/5 =  " << 9 / 5 << endl;
	cout << "Divisao Ponto-Flutuante: 9.0/5.0 =  " << 9.0 / 5.0 << endl;
	cout << "Divisao Mista: 9.0/5 =  " << 9.0 / 5 << endl;

	cout << endl;

	cout << "Constantes doulbe: 1e7/9.0 =  " << 1e7 / 9.0 << endl;
	cout << "Constantes float: 1e7f/9.0f =  " << 1e7f / 9.0f << endl;
	
	return 0;
}