/*
 * Produto.cpp
 *
 * Implementação de Produto.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "Produto.h"

namespace exercicio06 {
	Produto::Produto(int codigoBarras, const string& nome, double preco) {
		this->codigoBarras = codigoBarras;
		this->nome = nome;
		this->preco = preco;
	}

	void Produto::print(ostream &out) const {
		out << nome << "; R$ " << preco;
	}

	ostream& operator<< (ostream &out, const Produto &produto) {
		produto.print(out);
		return out;
	}

	bool operator==(const Produto& esq, const Produto& dir) {
		return esq.codigoBarras == dir.codigoBarras;
	}
}
