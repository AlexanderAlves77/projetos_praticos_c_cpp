/*
 * Livro.cpp
 *
 * Implementação de Livro.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Livro.h"

namespace exercicio06 {
	Livro::Livro(int codigoBarras, const string& nome, double preco, const string &autor): Produto(codigoBarras, nome, preco) {
		this->autor = autor;
	}

	void Livro::print(ostream &out) const {
		Produto::print(out);
		out << "; Autor: " << autor;
	}

	ostream& operator<< (ostream &out, Livro &livro) {
		livro.print(out);
		return out;
	}
}
