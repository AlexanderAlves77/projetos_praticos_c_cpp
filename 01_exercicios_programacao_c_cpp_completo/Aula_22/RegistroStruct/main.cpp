#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namesapece std;

struct jogador
{
	char nome[20];
	float salario;
	unsigned gols;
};

int main(int argc, char * argv[])
{
	jogadir zico;
	zico.gols = 700;
	zico.salario = 40000;
	strcpy(zico.nome, "Zico");
	
	cout << zico.nome << " fez " << zico.gols << " gols, recebendo R$ " << zico.salario << endl;
	
	return 0;
}

