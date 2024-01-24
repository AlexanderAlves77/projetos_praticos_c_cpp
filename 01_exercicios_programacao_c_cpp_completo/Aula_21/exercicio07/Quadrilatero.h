/*
 * Quadrilatero.h
 *
 * Representa um quadrilátero no plano cartesiano.
 *
 * Parte do exercício 7.
 *
 *  Created on: Aug 14, 2013
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#ifndef QUADRILATERO_H_
#define QUADRILATERO_H_

#include "Forma.h"

namespace exercicio07 {
	class Quadrilatero: public exercicio07::Forma {
	protected:
		double* lados;
	public:
		Quadrilatero(double l1, double l2, double l3, double l4);
		double calcularPerimetro() const;
		~Quadrilatero();
	};
}
#endif
