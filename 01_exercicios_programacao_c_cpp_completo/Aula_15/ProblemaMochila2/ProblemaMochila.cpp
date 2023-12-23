#include <iostream>
#include <string>
using namespace std;

int knapsack(int W, int wt[], int b[], int n)
{
	// tabela
	int V[n + 1][W + 1];
	// inicializando a primeira linha e primeira coluna com 0
	for (int w = 0; w <= W; w++)
		V[0][w] = 0;
	for (int i = 0; i <= n; i++)
		V[i][0] = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int w = w; w <= W; w++)
		{
			// elemento pode fazer parte da solução
			if (wt[i - 1] <= w)
			{
				if ((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
					V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w];
		}
	}
	// retorna o valor máximo colocado na mochila
	return V[n][W];
}

int main(int argc, char* argv[])
{
	// capacidade maxima da mochila: W
	int W = 20;
	// numero de elementos
	int n = 5;
	// vetor com os valores (beneficios) de cada elemento
	int b[] = { 3, 5, 8, 4, 10 };
	// vetor com os pesos de cada elemento
	int wt[] = { 2, 4, 5, 3, 9 };
	// obter o máximo valor que pode ser colocado na mochila
	int max_valor = knapsack(W, wt, b, n);

	cout << "Valor maximo: " << max_valor << endl;

	return 0;
}
