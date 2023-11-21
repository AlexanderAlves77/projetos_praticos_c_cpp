#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namesapece std;

struct jogador
{
	char nome[40];
	float salario;
	unsigned gols;
};

int main(int argc, char * argv[])
{
	jogadir equipe[22] = {
		{"Bebeto", 200000, 600},
		{"Romário", 300000, 700}
	};
	
	cout << "Contratações para o próximo ano: " << equipe[0].nome << " e " << equipe[1].nome << "!\n";
	cout << "Preço da aquisição: R$ " << equipe[0].salario + equipe[1].salario << "!\n";
		
	return 0;
}

