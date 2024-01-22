/*
 * CD.h
 *
 * Representa um CD vendido na loja.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef CD_H_
#define CD_H_

#include "Produto.h"

namespace exercicio06 {
	class CD: public Produto {
		int numeroFaixas;

	protected:
		virtual void print(ostream &out) const;

	public:
		CD(int codigoBarras, const string& nome, double preco, int numeroFaixas);
		friend ostream& operator<< (ostream &out, CD &cd);
	};
}
#endif
