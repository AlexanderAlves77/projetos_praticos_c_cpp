// Implementa��o do k-NN (k-nearest neighbors algorithm)
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
using namespace std;

class Individuo
{
private:
	string classe;
	double a, b, c, d;

public:
	Individuo(double a, double b, double c, double d, string classe)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->classe = classe;
	}

	string getClasse()
	{
		return classe;
	}

	double getA()
	{
		return a;
	}

	double getB()
	{
		return b;
	}

	double getC()
	{
		return c;
	}

	double getD()
	{
		return d;
	}
};

// fun��o que retorna a dist�ncia euclidiana entre 2 indiv�duos
double obterDistEuclidiana(Individuo ind1, Individuo ind2)
{
	/*
		a dist�ncia euclidiana � a raiz quadrada da soma das
		diferen�as dos valores dos atributos elevado ao quadrado
	*/
	double soma = pow((ind1.getA() - ind2.getA()), 2) + 
				  pow((ind1.getB() - ind2.getB()), 2) +
				  pow((ind1.getC() - ind2.getC()), 2) + 
				  pow((ind1.getD() - ind2.getD()), 2);

	return sqrt(soma);
}

// essa fun��o classifica uma nova amostra
string classificarAmostra(vector<Individuo>& individuos, Individuo novo_exemplo, int K)
{
	// se o K for par decrementa
	if (K % 2 == 0)
	{
		K--;
		if (K <= 0)
			K = 1;
	}

	int tam_vet = individuos.size();

	set<pair<double, int>> dist_individuos;

	for (int i = 0; i < tam_vet; i++)
	{
		double dist = obterDistEuclidiana(individuos[i], novo_exemplo);
		dist_individuos.insert(make_pair(dist, i));
	}
	set<pair<double, int>>::iterator it;

	vector<int> cont_classes(3);

	int contK = 0;

	for (it = dist_individuos.begin(); it != dist_individuos.end(); it++)
	{
		string classe = individuos[it->second].getClasse();

		if (classe == "Iris-setosa")
			cont_classes[0]++;
		else if (classe == "Iris-versicolor")
			cont_classes[1]++;
		else 
			cont_classes[2]++;

		if (contK > K) break;
		contK++;
	}

	string classe_classificacao;
	if (cont_classes[0] >= cont_classes[1] && cont_classes[0] >= cont_classes[2])
		classe_classificacao = "Iris-setosa";
	else if (cont_classes[1] >= cont_classes[0] && cont_classes[1] >= cont_classes[2])
		classe_classificacao = "Iris-versicolor";
	else 
		classe_classificacao = "Iris-virginica";

	return classe_classificacao;
}


int main(int argc, char* argv[])
{
	vector<Individuo> individuos;
	/*
		o K � a quantidade de vizinhos que ser�o levados em conta para classifica��o de um
		novo dado, � recomend�vel que seja �mpar para que n�o possa haver empate
	*/
	int K = 3;
	// tamanho do conjunto de dados de treinamento
	int tam_treinamento = 105;

	// o processo de treinamento consiste em apenas armazenar o conjunto de dados de treinamento
	for (int i = 0; i < tam_treinamento; i++)
	{
		string classe;
		double a, b, c, d;
		cin >> a >> b >> c >> d >> classe;

		individuos.push_back(Individuo(a, b, c, d, classe));
	}

	int acertos = 0;
	int tam_testes = 150 - tam_treinamento;

	// processo de classifica��o
	for (int i = 0; i < tam_testes; i++)
	{
		string classe;
		double a, b, c, d;
		cin >> a >> b >> c >> d >> classe;

		Individuo ind(a, b, c, d, classe);

		string classe_obtida = classificarAmostra(individuos, ind, K);

		cout << "Classe esperada: " << classe << "\n";
		cout << "Classe obtida: " << classe_obtida << "\n\n";

		if (classe == classe_obtida)
			acertos++;
	}

	cout << acertos << " acertos de um total de " << tam_testes << " testes.\n";

	return 0;
}
