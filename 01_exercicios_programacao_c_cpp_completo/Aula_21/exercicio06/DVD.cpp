/*
 * DVD.cpp
 *
 * Implementação de DVD.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include <iostream>
#include "DVD.h"

namespace exercicio06 {
	DVD::DVD(int codigoBarras, const string& nome, double preco, int duracao): Produto(codigoBarras, nome, preco)  {
		this->duracao = duracao;
	}

	void DVD::print(ostream &out) const {
		Produto::print(out);
		out << "; # duração: " << duracao;
	}

	ostream& operator<< (ostream &out, DVD &dvd) {
		dvd.print(out);
		return out;
	}
}
