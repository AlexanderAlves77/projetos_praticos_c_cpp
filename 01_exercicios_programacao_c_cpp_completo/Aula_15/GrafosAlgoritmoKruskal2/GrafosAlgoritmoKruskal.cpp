#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;
public:
	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}
	int obterVertice2()
	{
		return vertice2;
	}
	int obterPeso()
	{
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V;
	vector<Aresta> arestas;
public:
	Grafo(int V)
	{
		this->V = V;
	}

	// fun��o que adiciona uma aresta
	void adicionarAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	// fun��o que busca um subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if (subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// fun��o para unir dois subconjuntos em um �nico conjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	// fun��o que roda o algoritmo de Kruskal
	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor pre�o
		sort(arestas.begin(), arestas.end());

		// aloca mem�ria para criar "V" subconjuntos
		int* subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um �nico elemento
		memset(subset, -1, sizeof(int) * V);

		for (int i = 0; i < size_arestas; i++) 
		{
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if (v1 != v2)
			{
				// se forem diferente � porque N�O forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2);  // faz a uni�o
			}
		}
		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos pesos
		for (int i = 0; i < size_arvore; i++)
		{
			char v1 = 'A' + arvore[i].obterVertice1();
			char v2 = 'A' + arvore[i].obterVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
		}
	}
};


int main(int argc, char* argv[])
{
	Grafo g(7);

	g.adicionarAresta(0, 1, 7);
	g.adicionarAresta(0, 3, 5);
	g.adicionarAresta(1, 2, 8);
	g.adicionarAresta(1, 3, 9);
	g.adicionarAresta(1, 4, 7);
	g.adicionarAresta(2, 4, 5);
	g.adicionarAresta(3, 4, 15);
	g.adicionarAresta(3, 5, 6);
	g.adicionarAresta(4, 5, 8);
	g.adicionarAresta(4, 6, 9);
	g.adicionarAresta(5, 6, 11);

	g.kruskal();

	return 0;
}
