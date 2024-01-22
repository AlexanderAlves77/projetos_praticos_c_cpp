/*
 * DVD.h
 *
 * Representa um DVD vendido na loja.
 *
 * Parte do exercício 6.
 *
 *  Created on: Aug 13, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef DVD_H_
#define DVD_H_

#include "Produto.h"

namespace exercicio06 {
	class DVD: public Produto {
		int duracao;

	protected:
		virtual void print(ostream &out) const;

	public:
		DVD(int codigoBarras, const string& nome, double preco, int duracao);
		friend ostream& operator<< (ostream &out, DVD &dvd);
	};
}
#endif
