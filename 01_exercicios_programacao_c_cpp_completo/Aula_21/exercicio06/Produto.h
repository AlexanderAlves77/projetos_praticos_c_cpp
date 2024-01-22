/*
 * Produto.h
 *
 * Representa um produto vendido na loja.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>
#include <iostream>
using namespace std;

namespace exercicio06 {
	class Produto {
		int codigoBarras;
		string nome;
		double preco;

	protected:
		virtual void print(ostream &out) const;

	public:
		Produto(int codigoBarras, const string& nome, double preco);
		friend ostream& operator<< (ostream &out, const Produto &produto);
		friend bool operator==(const Produto& esq, const Produto& dir);
	};
}
#endif
