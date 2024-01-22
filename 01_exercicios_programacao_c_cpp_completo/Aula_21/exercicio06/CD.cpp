/*
 * CD.cpp
 *
 * Implementação de CD.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "CD.h"

namespace exercicio06 {
	CD::CD(int codigoBarras, const string& nome, double preco, int numeroFaixas): Produto(codigoBarras, nome, preco)  {
		this->numeroFaixas = numeroFaixas;
	}

	void CD::print(ostream &out) const {
		Produto::print(out);
		out << "; # faixas: " << numeroFaixas;
	}

	ostream& operator<< (ostream &out, CD &cd) {
		cd.print(out);
		return out;
	}
}
