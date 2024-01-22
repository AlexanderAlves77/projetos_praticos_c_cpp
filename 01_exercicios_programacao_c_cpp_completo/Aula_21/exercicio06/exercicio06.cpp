#include <iostream>
#include "Produto.h"
#include "Livro.h"
#include "CD.h"
#include "DVD.h"
using namespace std;

namespace exercicio06 {
	int buscarProduto(Produto* produto, Produto* produtos[], int tam) {
		for (int i = 0; i < tam; i++)
			if (*produtos[i] == *produto)
				return i;

		cout << "Produto não encontrado: " << produto << '\n';
		return -1;
	}

	void main() {
		Produto* produtos[5];
		produtos[0] = new CD(1, "Que país é este", 14.9, 9);
		produtos[1] = new DVD(2, "Matrix", 24.9, 90);
		produtos[2] = new Livro(3, "O Senhor dos Anéis", 39.9, "J. R. Tolkien");
		produtos[3] = new Livro(4, "Harry Potter", 39.9, "J. K. Rowling");
		produtos[4] = new DVD(5, "Inception", 29.9, 100);

		for (int i = 0; i < 5; i++)
			cout << *produtos[i] << '\n';

		Produto *p1 = new Livro(3, "O Senhor dos Anéis", 39.9, "J. R. Tolkien");
		Produto *p2 = new Livro(999, "O Senhor dos Anéis", 39.9, "J. R. Tolkien");
		int pos = buscarProduto(p1, produtos, 5);
		cout << "pos = " << pos << '\n';
		pos = buscarProduto(p2, produtos, 5);
		cout << "pos = " << pos << '\n';
	}
}
