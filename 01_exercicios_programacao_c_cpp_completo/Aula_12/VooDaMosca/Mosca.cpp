#include <iostream>
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

	while (resultante.Magnitude() < distancia)
	{
		magnitude = rand() % MagnitudeMax;
		direcao = rand() % AnguloMax;
		Vetor voo = { magnitude, direcao, Vetor::POL };
		resultante = resultante + voo;
		cont++;
	}

	cout << "---------------------------------------------------------\n";
	cout << "Foram " << cont << " passos de simulacao para chegar em:\n";
	cout << resultante << "\n";
	resultante.SetCoord(Vetor::POL);
	cout << resultante << "\n";
	cout << "---------------------------------------------------------\n";
	cout << "Distancia media por passo : " << distancia / cont << "\n";

	return 0;
}