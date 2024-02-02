#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Vetor.h"

int main()
{
	using namespace std;
	srand(unsigned(time(0)));

	const int MagnitudeMax = 10;
	const int AnguloMax = 360;

	cout << "Entre com a distancia alvo: ";
	double distancia;
	cin >> distancia;

	Vetor resultante;
	double magnitude;
	double direcao;

	int cont = 0;
	ofstream fout{ "voo.txt" };
	fout << "Distancia alvo: " << distancia << "\n";

	while (resultante.Magnitude() < distancia)
	{
		magnitude = rand() % MagnitudeMax;
		direcao = rand() % AnguloMax;
		Vetor voo = { magnitude, direcao, Vetor::POL };
		resultante = resultante + voo;
		cont++;
		fout << cont << ": " << resultante << "\n";
	}

	fout << "---------------------------------------------------------\n";
	fout << "Foram " << cont << " passos de simulacao para chegar em:\n";
	fout << resultante << "\n";
	resultante.SetCoord(Vetor::POL);
	fout << resultante << "\n";
	fout << "---------------------------------------------------------\n";
	fout << "Distancia media por passo : " << distancia / cont << "\n";
	fout.close();

	return 0;
}