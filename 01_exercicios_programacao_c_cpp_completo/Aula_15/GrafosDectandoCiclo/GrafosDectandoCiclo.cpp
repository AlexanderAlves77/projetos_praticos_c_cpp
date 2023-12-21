#include <iostream>
#include <list>
#include <stack>  // pilha para usar na DFS
using namespace std;

class Grafo
{
	int V;  // número de arestas
	list<int>* adj;  // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V);   // construtor
	void adicionarAresta(int v1, int v2);  // adiciona uma aresta no grafo

	// faz uma DFS a partir de un vértice, retorna se achou ciclo ou não
	bool dfs(int v);

	// verifica seo gráfico direcionado tem ciclo
	bool temCiclo();
};

Grafo::Grafo(int V)
{
	this->V = V;  // atribui o número de vértices
	adj = new list<int>[V];  // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V], pilha_rec[V];   // vetor de visitados

	// inicializa visitados e pilha_rec com false
	for (int i = 0; i < V; i++)
		visitados[i] = pilha_rec[i] = false;

	while (true)
	{
		bool achou_vizinho = false;
		list<int>::iterator it;

		if (!visitados[v])
		{
			pilha.push(v);
			visitados[v] = pilha_rec[v] = true;
		}		

		// busca por um vizinho não visitado
		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// se o vizinho já está na pilha é porque existe ciclo
			if (pilha_rec[*it])
				return true;
			else if (!visitados[*it])
			{
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}
		if (!achou_vizinho)
		{
			pilha_rec[pilha.top()] = false;  // marca que saiu da pilha
			pilha.pop();  //  remove da pilha
			if (pilha.empty())
				break;
			v = pilha.top();
		}
		else
			v = *it;
	}
	return false;
}

bool Grafo::temCiclo()
{
	for (int i = 0; i < V; i++)
	{
		if (dfs(i))
			return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	Grafo grafo(4);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(3, 0);
	
	if (grafo.temCiclo())
		cout << "Contem ciclo\n";
	else
		cout << "NAO contem ciclo\n";

	return 0;
}
