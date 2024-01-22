/*
 * Livro.h
 *
 * Representa um livro vendido na loja.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef LIVRO_H_
#define LIVRO_H_

#include <string>
#include "Produto.h"
using namespace std;

namespace exercicio06 {
	class Livro: public Produto {
		string autor;

	protected:
		virtual void print(ostream &out) const;

	public:
		Livro(int codigoBarras, const string& nome, double preco, const string &autor);
		friend ostream& operator<< (ostream &out, Livro &livro);
	};
}
#endif
