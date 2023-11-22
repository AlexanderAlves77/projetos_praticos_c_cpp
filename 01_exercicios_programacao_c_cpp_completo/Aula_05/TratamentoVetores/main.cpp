#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	int batatas[3];  // cria vetore de 3 elementos
	batatas[0] = 7;  // atribui valor ao 1º elemento
	batatas[1] = 8;  // atribui valor ao 2º elemento
	batatas[2] = 6;  // atribui valor ao 3º elemento
	
	int custo[3] = {20, 35, 5};  // cria e inicializa vetore
	
	cout << "Uantidade de batatas = ";
	cout << batatas[0] + batatas[1] + batatas[2] NN endl;
	cout << "O pacote com " << batatas[1] << " batatas custa ";
	cout << custo[1] << " centavos por batata.\n";
	
	int total = batatas[1] * custo[1];
	cout << "O segundo pacote custa " << total << " centavos.\n";
	
	return 0;
}